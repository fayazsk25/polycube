/**
* bridge API
* bridge API generated from bridge.yang
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
*/


/* Do not edit this file manually */

/*
* BridgeApiImpl.h
*
*
*/

#pragma once

#include "BridgeApi.h"


#include <memory>
#include <map>
#include "../Bridge.h"

#include "BridgeSchema.h"
#include "FilteringdatabaseSchema.h"
#include "PortsAccessSchema.h"
#include "PortsSchema.h"
#include "PortsStpSchema.h"
#include "PortsTrunkAllowedSchema.h"
#include "PortsTrunkSchema.h"
#include "StpSchema.h"
#include <vector>

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

class BridgeApiImpl : public io::swagger::server::api::BridgeApi {
public:
    BridgeApiImpl();
    ~BridgeApiImpl() { };

    BridgeSchema create_bridge_by_id(const std::string &name, const BridgeSchema &bridge);
    FilteringdatabaseSchema create_bridge_filteringdatabase_by_id(const std::string &name, const std::string &vlan, const std::string &address, const FilteringdatabaseSchema &filteringdatabase);
    std::vector<FilteringdatabaseSchema> create_bridge_filteringdatabase_list_by_id(const std::string &name, const std::vector<FilteringdatabaseSchema> &filteringdatabase);
    PortsAccessSchema create_bridge_ports_access_by_id(const std::string &name, const std::string &portsName, const PortsAccessSchema &access);
    PortsSchema create_bridge_ports_by_id(const std::string &name, const std::string &portsName, const PortsSchema &ports);
    std::vector<PortsSchema> create_bridge_ports_list_by_id(const std::string &name, const std::vector<PortsSchema> &ports);
    PortsStpSchema create_bridge_ports_stp_by_id(const std::string &name, const std::string &portsName, const std::string &vlan, const PortsStpSchema &stp);
    std::vector<PortsStpSchema> create_bridge_ports_stp_list_by_id(const std::string &name, const std::string &portsName, const std::vector<PortsStpSchema> &stp);
    PortsTrunkAllowedSchema create_bridge_ports_trunk_allowed_by_id(const std::string &name, const std::string &portsName, const std::string &vlanid, const PortsTrunkAllowedSchema &allowed);
    std::vector<PortsTrunkAllowedSchema> create_bridge_ports_trunk_allowed_list_by_id(const std::string &name, const std::string &portsName, const std::vector<PortsTrunkAllowedSchema> &allowed);
    PortsTrunkSchema create_bridge_ports_trunk_by_id(const std::string &name, const std::string &portsName, const PortsTrunkSchema &trunk);
    StpSchema create_bridge_stp_by_id(const std::string &name, const std::string &vlan, const StpSchema &stp);
    std::vector<StpSchema> create_bridge_stp_list_by_id(const std::string &name, const std::vector<StpSchema> &stp);
    void delete_bridge_by_id(const std::string &name);
    void delete_bridge_filteringdatabase_by_id(const std::string &name, const std::string &vlan, const std::string &address);
    void delete_bridge_filteringdatabase_list_by_id(const std::string &name);
    void delete_bridge_ports_access_by_id(const std::string &name, const std::string &portsName);
    void delete_bridge_ports_by_id(const std::string &name, const std::string &portsName);
    void delete_bridge_ports_list_by_id(const std::string &name);
    void delete_bridge_ports_stp_by_id(const std::string &name, const std::string &portsName, const std::string &vlan);
    void delete_bridge_ports_stp_list_by_id(const std::string &name, const std::string &portsName);
    void delete_bridge_ports_trunk_allowed_by_id(const std::string &name, const std::string &portsName, const std::string &vlanid);
    void delete_bridge_ports_trunk_allowed_list_by_id(const std::string &name, const std::string &portsName);
    void delete_bridge_ports_trunk_by_id(const std::string &name, const std::string &portsName);
    void delete_bridge_stp_by_id(const std::string &name, const std::string &vlan);
    void delete_bridge_stp_list_by_id(const std::string &name);
    int32_t read_bridge_agingtime_by_id(const std::string &name);
    BridgeSchema read_bridge_by_id(const std::string &name);
    int32_t read_bridge_filteringdatabase_age_by_id(const std::string &name, const std::string &vlan, const std::string &address);
    FilteringdatabaseSchema read_bridge_filteringdatabase_by_id(const std::string &name, const std::string &vlan, const std::string &address);
    std::string read_bridge_filteringdatabase_entrytype_by_id(const std::string &name, const std::string &vlan, const std::string &address);
    std::vector<FilteringdatabaseSchema> read_bridge_filteringdatabase_list_by_id(const std::string &name);
    std::vector<std::string> read_bridge_filteringdatabase_list_by_id_get_list();
    std::string read_bridge_filteringdatabase_port_by_id(const std::string &name, const std::string &vlan, const std::string &address);
    std::vector<BridgeSchema> read_bridge_list_by_id();
    std::vector<std::string> read_bridge_list_by_id_get_list();
    PortsAccessSchema read_bridge_ports_access_by_id(const std::string &name, const std::string &portsName);
    int32_t read_bridge_ports_access_vlanid_by_id(const std::string &name, const std::string &portsName);
    std::string read_bridge_ports_address_by_id(const std::string &name, const std::string &portsName);
    PortsSchema read_bridge_ports_by_id(const std::string &name, const std::string &portsName);
    std::vector<PortsSchema> read_bridge_ports_list_by_id(const std::string &name);
    std::vector<std::string> read_bridge_ports_list_by_id_get_list();
    std::string read_bridge_ports_mode_by_id(const std::string &name, const std::string &portsName);
    std::string read_bridge_ports_peer_by_id(const std::string &name, const std::string &portsName);
    std::string read_bridge_ports_status_by_id(const std::string &name, const std::string &portsName);
    PortsStpSchema read_bridge_ports_stp_by_id(const std::string &name, const std::string &portsName, const std::string &vlan);
    std::vector<PortsStpSchema> read_bridge_ports_stp_list_by_id(const std::string &name, const std::string &portsName);
    std::vector<std::string> read_bridge_ports_stp_list_by_id_get_list();
    int32_t read_bridge_ports_stp_pathcost_by_id(const std::string &name, const std::string &portsName, const std::string &vlan);
    int32_t read_bridge_ports_stp_portpriority_by_id(const std::string &name, const std::string &portsName, const std::string &vlan);
    std::string read_bridge_ports_stp_state_by_id(const std::string &name, const std::string &portsName, const std::string &vlan);
    PortsTrunkAllowedSchema read_bridge_ports_trunk_allowed_by_id(const std::string &name, const std::string &portsName, const std::string &vlanid);
    std::vector<PortsTrunkAllowedSchema> read_bridge_ports_trunk_allowed_list_by_id(const std::string &name, const std::string &portsName);
    std::vector<std::string> read_bridge_ports_trunk_allowed_list_by_id_get_list();
    PortsTrunkSchema read_bridge_ports_trunk_by_id(const std::string &name, const std::string &portsName);
    int32_t read_bridge_ports_trunk_nativevlan_by_id(const std::string &name, const std::string &portsName);
    std::string read_bridge_ports_uuid_by_id(const std::string &name, const std::string &portsName);
    std::string read_bridge_stp_address_by_id(const std::string &name, const std::string &vlan);
    StpSchema read_bridge_stp_by_id(const std::string &name, const std::string &vlan);
    int32_t read_bridge_stp_forwarddelay_by_id(const std::string &name, const std::string &vlan);
    int32_t read_bridge_stp_hellotime_by_id(const std::string &name, const std::string &vlan);
    std::vector<StpSchema> read_bridge_stp_list_by_id(const std::string &name);
    std::vector<std::string> read_bridge_stp_list_by_id_get_list();
    int32_t read_bridge_stp_maxmessageage_by_id(const std::string &name, const std::string &vlan);
    int32_t read_bridge_stp_priority_by_id(const std::string &name, const std::string &vlan);
    std::string read_bridge_type_by_id(const std::string &name);
    bool read_bridge_stpenabled_by_id(const std::string &name);
    std::string read_bridge_uuid_by_id(const std::string &name);
    void update_bridge_agingtime_by_id(const std::string &name, const int32_t &agingtime);
    void update_bridge_by_id(const std::string &name, const BridgeSchema &bridge);
    void update_bridge_filteringdatabase_by_id(const std::string &name, const std::string &vlan, const std::string &address, const FilteringdatabaseSchema &filteringdatabase);
    void update_bridge_filteringdatabase_entrytype_by_id(const std::string &name, const std::string &vlan, const std::string &address, const std::string &entrytype);
    void update_bridge_filteringdatabase_list_by_id(const std::string &name, const std::vector<FilteringdatabaseSchema> &filteringdatabase);
    void update_bridge_filteringdatabase_port_by_id(const std::string &name, const std::string &vlan, const std::string &address, const std::string &port);
    void update_bridge_ports_access_by_id(const std::string &name, const std::string &portsName, const PortsAccessSchema &access);
    void update_bridge_ports_access_vlanid_by_id(const std::string &name, const std::string &portsName, const int32_t &vlanid);
    void update_bridge_ports_address_by_id(const std::string &name, const std::string &portsName, const std::string &address);
    void update_bridge_ports_by_id(const std::string &name, const std::string &portsName, const PortsSchema &ports);
    void update_bridge_ports_list_by_id(const std::string &name, const std::vector<PortsSchema> &ports);
    void update_bridge_ports_mode_by_id(const std::string &name, const std::string &portsName, const std::string &mode);
    void update_bridge_ports_peer_by_id(const std::string &name, const std::string &portsName, const std::string &peer);
    void update_bridge_ports_status_by_id(const std::string &name, const std::string &portsName, const std::string &status);
    void update_bridge_ports_stp_by_id(const std::string &name, const std::string &portsName, const std::string &vlan, const PortsStpSchema &stp);
    void update_bridge_ports_stp_list_by_id(const std::string &name, const std::string &portsName, const std::vector<PortsStpSchema> &stp);
    void update_bridge_ports_stp_pathcost_by_id(const std::string &name, const std::string &portsName, const std::string &vlan, const int32_t &pathcost);
    void update_bridge_ports_stp_portpriority_by_id(const std::string &name, const std::string &portsName, const std::string &vlan, const int32_t &portpriority);
    void update_bridge_ports_trunk_allowed_by_id(const std::string &name, const std::string &portsName, const std::string &vlanid, const PortsTrunkAllowedSchema &allowed);
    void update_bridge_ports_trunk_allowed_list_by_id(const std::string &name, const std::string &portsName, const std::vector<PortsTrunkAllowedSchema> &allowed);
    void update_bridge_ports_trunk_by_id(const std::string &name, const std::string &portsName, const PortsTrunkSchema &trunk);
    void update_bridge_ports_trunk_nativevlan_by_id(const std::string &name, const std::string &portsName, const int32_t &nativevlan);
    void update_bridge_stp_address_by_id(const std::string &name, const std::string &vlan, const std::string &address);
    void update_bridge_stp_by_id(const std::string &name, const std::string &vlan, const StpSchema &stp);
    void update_bridge_stp_forwarddelay_by_id(const std::string &name, const std::string &vlan, const int32_t &forwarddelay);
    void update_bridge_stp_hellotime_by_id(const std::string &name, const std::string &vlan, const int32_t &hellotime);
    void update_bridge_stp_list_by_id(const std::string &name, const std::vector<StpSchema> &stp);
    void update_bridge_stp_maxmessageage_by_id(const std::string &name, const std::string &vlan, const int32_t &maxmessageage);
    void update_bridge_stp_priority_by_id(const std::string &name, const std::string &vlan, const int32_t &priority);
    void update_bridge_stpenabled_by_id(const std::string &name, const bool &stpenabled);
    void update_bridge_type_by_id(const std::string &name, const std::string &type);
    static CubeType string_to_type(const std::string &type);
private:
    std::unordered_map<std::string, Bridge> cubes;
    Bridge &get_cube(const std::string &name);
};

}
}
}
}

