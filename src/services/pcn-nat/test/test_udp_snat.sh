#!/usr/bin/env bash

#         TOPOLOGY
#
#                              +-----------+                 +-----------+
#      veth1 (10.0.1.1)--------|     r1    |-----------------|    nat1   |------- veth2 (10.0.2.1)
#                            ^ +-----------+  ^            ^ +-----------+  ^
#                            |                |            |                |
#                          to_veth1        to_nat1  to_r1 (INTERNAL)    to_veth2 (EXTERNAL)
#

# TEST 8
# test UDP with netcat and source nat

source "${BASH_SOURCE%/*}/helpers.bash"

function test_udp {
	npingOutput="$(sudo ip netns exec ns1 nping --udp -c 1 -p $udp_port --source-port 50000 $veth2_ip)"
    if [[ $npingOutput != *"Rcvd: 1"* ]]; then
        exit 1
    fi
}

function cleanup {
    set +e
    delete_veth 2
    polycubectl nat del nat1
    polycubectl router del r1
}
trap cleanup EXIT

veth1_ip=10.0.1.1
veth2_ip=10.0.2.1
to_nat_ip=10.0.2.254
to_veth1_ip=10.0.1.254
udp_port=3000

set -x
set -e

create_veth_net 2

polycubectl nat add nat1
polycubectl router add r1

polycubectl router r1 ports add to_veth1 ip=$to_veth1_ip netmask=255.255.255.0
polycubectl router r1 ports to_veth1 set peer=veth1
polycubectl router r1 ports add to_nat1 ip=$to_nat_ip netmask=255.255.255.0

polycubectl nat1 ports add to_r1 type=INTERNAL
polycubectl connect nat1:to_r1 r1:to_nat1

polycubectl nat1 ports add to_veth2 type=EXTERNAL ip=$to_nat_ip
polycubectl connect nat1:to_veth2 veth2

# Add rule for the ICMP Destination Unreachable packet that comes back
polycubectl nat1 rule dnat append external-ip=$to_nat_ip internal-ip=$veth1_ip

# Add rule for the UDP packet
polycubectl nat1 rule snat append internal-net=10.0.1.0/24 external-ip=$to_nat_ip

test_udp
