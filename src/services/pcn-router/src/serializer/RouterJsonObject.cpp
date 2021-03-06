/**
* router API
* Router Service
*
* OpenAPI spec version: 2.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */



#include "RouterJsonObject.h"
#include <regex>

namespace io {
namespace swagger {
namespace server {
namespace model {

RouterJsonObject::RouterJsonObject() {

  m_nameIsSet = false;

  m_uuidIsSet = false;

  m_type = CubeType::TC;
  m_typeIsSet = false;

  m_loglevel = RouterLoglevelEnum::INFO;
  m_loglevelIsSet = false;

  m_portsIsSet = false;

  m_routeIsSet = false;

  m_arpEntryIsSet = false;
}

RouterJsonObject::~RouterJsonObject() {}

void RouterJsonObject::validateKeys() {

  if (!m_nameIsSet) {
    throw std::runtime_error("Variable name is required");
  }
}

void RouterJsonObject::validateMandatoryFields() {

}

void RouterJsonObject::validateParams() {

  if (m_uuidIsSet) {
    std::string patter_value = R"PATTERN([0-9a-f]{8}-[0-9a-f]{4}-[1-5][0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12})PATTERN";
    std::regex e (patter_value);
    if (!std::regex_match(m_uuid, e))
      throw std::runtime_error("Variable uuid has not a valid format");
  }
}

nlohmann::json RouterJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  if (m_nameIsSet) {
    val["name"] = m_name;
  }

  if (m_uuidIsSet) {
    val["uuid"] = m_uuid;
  }

  if (m_typeIsSet) {
    val["type"] = CubeType_to_string(m_type);
  }

  if (m_loglevelIsSet) {
    val["loglevel"] = RouterLoglevelEnum_to_string(m_loglevel);
  }

  {
    nlohmann::json jsonArray;
    for (auto& item : m_ports) {
      jsonArray.push_back(JsonObjectBase::toJson(item));
    }

    if (jsonArray.size() > 0) {
      val["ports"] = jsonArray;
    }
  }
  {
    nlohmann::json jsonArray;
    for (auto& item : m_route) {
      jsonArray.push_back(JsonObjectBase::toJson(item));
    }

    if (jsonArray.size() > 0) {
      val["route"] = jsonArray;
    }
  }
  {
    nlohmann::json jsonArray;
    for (auto& item : m_arpEntry) {
      jsonArray.push_back(JsonObjectBase::toJson(item));
    }

    if (jsonArray.size() > 0) {
      val["arp-entry"] = jsonArray;
    }
  }

  return val;
}

void RouterJsonObject::fromJson(nlohmann::json& val) {
  for(nlohmann::json::iterator it = val.begin(); it != val.end(); ++it) {
    std::string key = it.key();
    bool found = (std::find(allowedParameters_.begin(), allowedParameters_.end(), key) != allowedParameters_.end());
    if (!found) {
      throw std::runtime_error(key + " is not a valid parameter");
      return;
    }
  }

  if (val.find("name") != val.end()) {
    setName(val.at("name"));
  }

  if (val.find("uuid") != val.end()) {
    setUuid(val.at("uuid"));
  }

  if (val.find("type") != val.end()) {
    setType(string_to_CubeType(val.at("type")));
  }

  if (val.find("loglevel") != val.end()) {
    setLoglevel(string_to_RouterLoglevelEnum(val.at("loglevel")));
  }

  m_ports.clear();
  for (auto& item : val["ports"]) {

    PortsJsonObject newItem;
    newItem.fromJson(item);
    m_ports.push_back(newItem);
    m_portsIsSet = true;
  }


  m_route.clear();
  for (auto& item : val["route"]) {

    RouteJsonObject newItem;
    newItem.fromJson(item);
    m_route.push_back(newItem);
    m_routeIsSet = true;
  }


  m_arpEntry.clear();
  for (auto& item : val["arp-entry"]) {

    ArpEntryJsonObject newItem;
    newItem.fromJson(item);
    m_arpEntry.push_back(newItem);
    m_arpEntryIsSet = true;
  }

}

nlohmann::json RouterJsonObject::helpKeys() {
  nlohmann::json val = nlohmann::json::object();

  val["name"]["name"] = "name";
  val["name"]["type"] = "key";
  val["name"]["simpletype"] = "string";
  val["name"]["description"] = R"POLYCUBE(Name of the router service)POLYCUBE";
  val["name"]["example"] = R"POLYCUBE(router1)POLYCUBE";

  return val;
}

nlohmann::json RouterJsonObject::helpElements() {
  nlohmann::json val = nlohmann::json::object();

  val["uuid"]["name"] = "uuid";
  val["uuid"]["type"] = "leaf"; // Suppose that type is leaf
  val["uuid"]["simpletype"] = "string";
  val["uuid"]["description"] = R"POLYCUBE(UUID of the Cube)POLYCUBE";
  val["uuid"]["example"] = R"POLYCUBE()POLYCUBE";
  val["type"]["name"] = "type";
  val["type"]["type"] = "leaf"; // Suppose that type is leaf
  val["type"]["simpletype"] = "string";
  val["type"]["description"] = R"POLYCUBE(Type of the Cube (TC, XDP_SKB, XDP_DRV))POLYCUBE";
  val["type"]["example"] = R"POLYCUBE(TC)POLYCUBE";
  val["loglevel"]["name"] = "loglevel";
  val["loglevel"]["type"] = "leaf"; // Suppose that type is leaf
  val["loglevel"]["simpletype"] = "string";
  val["loglevel"]["description"] = R"POLYCUBE(Defines the logging level of a service instance, from none (OFF) to the most verbose (TRACE))POLYCUBE";
  val["loglevel"]["example"] = R"POLYCUBE(INFO)POLYCUBE";
  val["ports"]["name"] = "ports";
  val["ports"]["type"] = "leaf"; // Suppose that type is leaf
  val["ports"]["type"] = "list";
  val["ports"]["description"] = R"POLYCUBE(Entry of the ports table)POLYCUBE";
  val["ports"]["example"] = R"POLYCUBE()POLYCUBE";
  val["route"]["name"] = "route";
  val["route"]["type"] = "leaf"; // Suppose that type is leaf
  val["route"]["type"] = "list";
  val["route"]["description"] = R"POLYCUBE(Entry associated with the routing table)POLYCUBE";
  val["route"]["example"] = R"POLYCUBE()POLYCUBE";
  val["arp-entry"]["name"] = "arp-entry";
  val["arp-entry"]["type"] = "leaf"; // Suppose that type is leaf
  val["arp-entry"]["type"] = "list";
  val["arp-entry"]["description"] = R"POLYCUBE(Entry associated with the ARP table)POLYCUBE";
  val["arp-entry"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

nlohmann::json RouterJsonObject::helpWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();

  val["loglevel"]["name"] = "loglevel";
  val["loglevel"]["simpletype"] = "string";
  val["loglevel"]["description"] = R"POLYCUBE(Defines the logging level of a service instance, from none (OFF) to the most verbose (TRACE))POLYCUBE";
  val["loglevel"]["example"] = R"POLYCUBE(INFO)POLYCUBE";

  return val;
}

nlohmann::json RouterJsonObject::helpComplexElements() {
  nlohmann::json val = nlohmann::json::object();

  val["ports"]["name"] = "ports";
  val["ports"]["type"] = "list";
  val["ports"]["description"] = R"POLYCUBE(Entry of the ports table)POLYCUBE";
  val["ports"]["example"] = R"POLYCUBE()POLYCUBE";
  val["route"]["name"] = "route";
  val["route"]["type"] = "list";
  val["route"]["description"] = R"POLYCUBE(Entry associated with the routing table)POLYCUBE";
  val["route"]["example"] = R"POLYCUBE()POLYCUBE";
  val["arp-entry"]["name"] = "arp-entry";
  val["arp-entry"]["type"] = "list";
  val["arp-entry"]["description"] = R"POLYCUBE(Entry associated with the ARP table)POLYCUBE";
  val["arp-entry"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

std::vector<std::string> RouterJsonObject::helpActions() {
  std::vector<std::string> val;
  return val;
}

std::string RouterJsonObject::getName() const {
  return m_name;
}

void RouterJsonObject::setName(std::string value) {
  m_name = value;
  m_nameIsSet = true;
}

bool RouterJsonObject::nameIsSet() const {
  return m_nameIsSet;
}

void RouterJsonObject::unsetName() {
  m_nameIsSet = false;
}



std::string RouterJsonObject::getUuid() const {
  return m_uuid;
}

void RouterJsonObject::setUuid(std::string value) {
  m_uuid = value;
  m_uuidIsSet = true;
}

bool RouterJsonObject::uuidIsSet() const {
  return m_uuidIsSet;
}

void RouterJsonObject::unsetUuid() {
  m_uuidIsSet = false;
}



CubeType RouterJsonObject::getType() const {
  return m_type;
}

void RouterJsonObject::setType(CubeType value) {
  m_type = value;
  m_typeIsSet = true;
}

bool RouterJsonObject::typeIsSet() const {
  return m_typeIsSet;
}

void RouterJsonObject::unsetType() {
  m_typeIsSet = false;
}

std::string RouterJsonObject::CubeType_to_string(const CubeType &value){
  switch(value){
    case CubeType::TC:
      return std::string("TC");
    case CubeType::XDP_SKB:
      return std::string("XDP_SKB");
    case CubeType::XDP_DRV:
      return std::string("XDP_DRV");
    default:
      throw std::runtime_error("Bad Router type");
  }
}

CubeType RouterJsonObject::string_to_CubeType(const std::string &str){
  if (JsonObjectBase::iequals("TC", str))
    return CubeType::TC;
  if (JsonObjectBase::iequals("XDP_SKB", str))
    return CubeType::XDP_SKB;
  if (JsonObjectBase::iequals("XDP_DRV", str))
    return CubeType::XDP_DRV;
  throw std::runtime_error("Router type is invalid");
}


RouterLoglevelEnum RouterJsonObject::getLoglevel() const {
  return m_loglevel;
}

void RouterJsonObject::setLoglevel(RouterLoglevelEnum value) {
  m_loglevel = value;
  m_loglevelIsSet = true;
}

bool RouterJsonObject::loglevelIsSet() const {
  return m_loglevelIsSet;
}

void RouterJsonObject::unsetLoglevel() {
  m_loglevelIsSet = false;
}

std::string RouterJsonObject::RouterLoglevelEnum_to_string(const RouterLoglevelEnum &value){
  switch(value){
    case RouterLoglevelEnum::TRACE:
      return std::string("trace");
    case RouterLoglevelEnum::DEBUG:
      return std::string("debug");
    case RouterLoglevelEnum::INFO:
      return std::string("info");
    case RouterLoglevelEnum::WARN:
      return std::string("warn");
    case RouterLoglevelEnum::ERR:
      return std::string("err");
    case RouterLoglevelEnum::CRITICAL:
      return std::string("critical");
    case RouterLoglevelEnum::OFF:
      return std::string("off");
    default:
      throw std::runtime_error("Bad Router loglevel");
  }
}

RouterLoglevelEnum RouterJsonObject::string_to_RouterLoglevelEnum(const std::string &str){
  if (JsonObjectBase::iequals("trace", str))
    return RouterLoglevelEnum::TRACE;
  if (JsonObjectBase::iequals("debug", str))
    return RouterLoglevelEnum::DEBUG;
  if (JsonObjectBase::iequals("info", str))
    return RouterLoglevelEnum::INFO;
  if (JsonObjectBase::iequals("warn", str))
    return RouterLoglevelEnum::WARN;
  if (JsonObjectBase::iequals("err", str))
    return RouterLoglevelEnum::ERR;
  if (JsonObjectBase::iequals("critical", str))
    return RouterLoglevelEnum::CRITICAL;
  if (JsonObjectBase::iequals("off", str))
    return RouterLoglevelEnum::OFF;
  throw std::runtime_error("Router loglevel is invalid");
}

  polycube::LogLevel RouterJsonObject::getPolycubeLoglevel() const {
    switch(m_loglevel) {
      case RouterLoglevelEnum::TRACE:
        return polycube::LogLevel::TRACE;
      case RouterLoglevelEnum::DEBUG:
        return polycube::LogLevel::DEBUG;
      case RouterLoglevelEnum::INFO:
        return polycube::LogLevel::INFO;
      case RouterLoglevelEnum::WARN:
        return polycube::LogLevel::WARN;
      case RouterLoglevelEnum::ERR:
        return polycube::LogLevel::ERR;
      case RouterLoglevelEnum::CRITICAL:
        return polycube::LogLevel::CRITICAL;
      case RouterLoglevelEnum::OFF:
        return polycube::LogLevel::OFF;
    }
  }
const std::vector<PortsJsonObject>& RouterJsonObject::getPorts() const{
  return m_ports;
}

void RouterJsonObject::addPorts(PortsJsonObject value) {
  m_ports.push_back(value);
}


bool RouterJsonObject::portsIsSet() const {
  return m_portsIsSet;
}

void RouterJsonObject::unsetPorts() {
  m_portsIsSet = false;
}



const std::vector<RouteJsonObject>& RouterJsonObject::getRoute() const{
  return m_route;
}

void RouterJsonObject::addRoute(RouteJsonObject value) {
  m_route.push_back(value);
}


bool RouterJsonObject::routeIsSet() const {
  return m_routeIsSet;
}

void RouterJsonObject::unsetRoute() {
  m_routeIsSet = false;
}



const std::vector<ArpEntryJsonObject>& RouterJsonObject::getArpEntry() const{
  return m_arpEntry;
}

void RouterJsonObject::addArpEntry(ArpEntryJsonObject value) {
  m_arpEntry.push_back(value);
}


bool RouterJsonObject::arpEntryIsSet() const {
  return m_arpEntryIsSet;
}

void RouterJsonObject::unsetArpEntry() {
  m_arpEntryIsSet = false;
}




}
}
}
}

