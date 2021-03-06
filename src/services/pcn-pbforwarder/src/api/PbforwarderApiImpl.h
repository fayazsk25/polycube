/**
* pbforwarder API
* Policy-Based Forwarder Service
*
* OpenAPI spec version: 2.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */

/*
* PbforwarderApiImpl.h
*
*
*/

#pragma once

#include "PbforwarderApi.h"


#include <memory>
#include <map>
#include <mutex>
#include "../Pbforwarder.h"

#include "PbforwarderJsonObject.h"
#include "PortsJsonObject.h"
#include "RulesJsonObject.h"
#include <vector>

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

class PbforwarderApiImpl : public io::swagger::server::api::PbforwarderApi {
public:
  PbforwarderApiImpl();
  ~PbforwarderApiImpl() { };

  void create_pbforwarder_by_id(const std::string &name, const PbforwarderJsonObject &value);
  void create_pbforwarder_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value);
  void create_pbforwarder_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value);
  void create_pbforwarder_rules_by_id(const std::string &name, const uint32_t &id, const RulesJsonObject &value);
  void create_pbforwarder_rules_list_by_id(const std::string &name, const std::vector<RulesJsonObject> &value);
  void delete_pbforwarder_by_id(const std::string &name);
  void delete_pbforwarder_ports_by_id(const std::string &name, const std::string &portsName);
  void delete_pbforwarder_ports_list_by_id(const std::string &name);
  void delete_pbforwarder_rules_by_id(const std::string &name, const uint32_t &id);
  void delete_pbforwarder_rules_list_by_id(const std::string &name);
  PbforwarderJsonObject read_pbforwarder_by_id(const std::string &name);
  std::vector<PbforwarderJsonObject> read_pbforwarder_list_by_id();
  std::vector<nlohmann::fifo_map<std::string, std::string>> read_pbforwarder_list_by_id_get_list();
  PbforwarderLoglevelEnum read_pbforwarder_loglevel_by_id(const std::string &name);
  PortsJsonObject read_pbforwarder_ports_by_id(const std::string &name, const std::string &portsName);
  std::vector<PortsJsonObject> read_pbforwarder_ports_list_by_id(const std::string &name);
  std::vector<nlohmann::fifo_map<std::string, std::string>> read_pbforwarder_ports_list_by_id_get_list(const std::string &name);
  std::string read_pbforwarder_ports_peer_by_id(const std::string &name, const std::string &portsName);
  PortsStatusEnum read_pbforwarder_ports_status_by_id(const std::string &name, const std::string &portsName);
  std::string read_pbforwarder_ports_uuid_by_id(const std::string &name, const std::string &portsName);
  RulesActionEnum read_pbforwarder_rules_action_by_id(const std::string &name, const uint32_t &id);
  RulesJsonObject read_pbforwarder_rules_by_id(const std::string &name, const uint32_t &id);
  std::string read_pbforwarder_rules_dst_ip_by_id(const std::string &name, const uint32_t &id);
  std::string read_pbforwarder_rules_dst_mac_by_id(const std::string &name, const uint32_t &id);
  uint16_t read_pbforwarder_rules_dst_port_by_id(const std::string &name, const uint32_t &id);
  std::string read_pbforwarder_rules_in_port_by_id(const std::string &name, const uint32_t &id);
  RulesL4ProtoEnum read_pbforwarder_rules_l4_proto_by_id(const std::string &name, const uint32_t &id);
  std::vector<RulesJsonObject> read_pbforwarder_rules_list_by_id(const std::string &name);
  std::vector<nlohmann::fifo_map<std::string, std::string>> read_pbforwarder_rules_list_by_id_get_list(const std::string &name);
  std::string read_pbforwarder_rules_out_port_by_id(const std::string &name, const uint32_t &id);
  std::string read_pbforwarder_rules_src_ip_by_id(const std::string &name, const uint32_t &id);
  std::string read_pbforwarder_rules_src_mac_by_id(const std::string &name, const uint32_t &id);
  uint16_t read_pbforwarder_rules_src_port_by_id(const std::string &name, const uint32_t &id);
  uint32_t read_pbforwarder_rules_vlan_by_id(const std::string &name, const uint32_t &id);
  CubeType read_pbforwarder_type_by_id(const std::string &name);
  std::string read_pbforwarder_uuid_by_id(const std::string &name);
  void replace_pbforwarder_by_id(const std::string &name, const PbforwarderJsonObject &value);
  void replace_pbforwarder_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value);
  void replace_pbforwarder_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value);
  void replace_pbforwarder_rules_by_id(const std::string &name, const uint32_t &id, const RulesJsonObject &value);
  void replace_pbforwarder_rules_list_by_id(const std::string &name, const std::vector<RulesJsonObject> &value);
  void update_pbforwarder_by_id(const std::string &name, const PbforwarderJsonObject &value);
  void update_pbforwarder_list_by_id(const std::vector<PbforwarderJsonObject> &value);
  void update_pbforwarder_loglevel_by_id(const std::string &name, const PbforwarderLoglevelEnum &value);
  void update_pbforwarder_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value);
  void update_pbforwarder_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value);
  void update_pbforwarder_ports_peer_by_id(const std::string &name, const std::string &portsName, const std::string &value);
  void update_pbforwarder_rules_action_by_id(const std::string &name, const uint32_t &id, const RulesActionEnum &value);
  void update_pbforwarder_rules_by_id(const std::string &name, const uint32_t &id, const RulesJsonObject &value);
  void update_pbforwarder_rules_dst_ip_by_id(const std::string &name, const uint32_t &id, const std::string &value);
  void update_pbforwarder_rules_dst_mac_by_id(const std::string &name, const uint32_t &id, const std::string &value);
  void update_pbforwarder_rules_dst_port_by_id(const std::string &name, const uint32_t &id, const uint16_t &value);
  void update_pbforwarder_rules_in_port_by_id(const std::string &name, const uint32_t &id, const std::string &value);
  void update_pbforwarder_rules_l4_proto_by_id(const std::string &name, const uint32_t &id, const RulesL4ProtoEnum &value);
  void update_pbforwarder_rules_list_by_id(const std::string &name, const std::vector<RulesJsonObject> &value);
  void update_pbforwarder_rules_out_port_by_id(const std::string &name, const uint32_t &id, const std::string &value);
  void update_pbforwarder_rules_src_ip_by_id(const std::string &name, const uint32_t &id, const std::string &value);
  void update_pbforwarder_rules_src_mac_by_id(const std::string &name, const uint32_t &id, const std::string &value);
  void update_pbforwarder_rules_src_port_by_id(const std::string &name, const uint32_t &id, const uint16_t &value);
  void update_pbforwarder_rules_vlan_by_id(const std::string &name, const uint32_t &id, const uint32_t &value);

private:
  std::unordered_map<std::string, std::shared_ptr<Pbforwarder>> cubes;
  std::shared_ptr<Pbforwarder> get_cube(const std::string &name);
  std::mutex cubes_mutex;
};

}
}
}
}

