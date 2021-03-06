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

#include "FilteringdatabaseSchema.h"

namespace io {
namespace swagger {
namespace server {
namespace model {

FilteringdatabaseSchema::FilteringdatabaseSchema() {
  m_Age = 0;
  m_AgeIsSet = false;
  m_Vlan = 0;
  m_VlanIsSet = false;
  m_Port = "";
  m_PortIsSet = false;
  m_Address = "";
  m_AddressIsSet = false;
  m_Entrytype = "";
  m_EntrytypeIsSet = false;
}

FilteringdatabaseSchema::~FilteringdatabaseSchema() {}

void FilteringdatabaseSchema::validate() {
  // TODO: implement validation
}

nlohmann::json FilteringdatabaseSchema::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  if (m_AgeIsSet) {
    val["age"] = m_Age;
  }

  if (m_VlanIsSet) {
    val["vlan"] = m_Vlan;
  }

  if (m_PortIsSet) {
    val["port"] = m_Port;
  }

  if (m_AddressIsSet) {
    val["address"] = m_Address;
  }

  if (m_EntrytypeIsSet) {
    val["entrytype"] = m_Entrytype;
  }

  return val;
}

void FilteringdatabaseSchema::fromJson(nlohmann::json &val) {
  if (val.find("age") != val.end()) {
    setAge(val.at("age"));
  }

  if (val.find("vlan") != val.end()) {
    setVlan(val.at("vlan"));
  }

  if (val.find("port") != val.end()) {
    setPort(val.at("port"));
  }

  if (val.find("address") != val.end()) {
    setAddress(val.at("address"));
  }

  if (val.find("entrytype") != val.end()) {
    setEntrytype(val.at("entrytype"));
  }
}

nlohmann::json FilteringdatabaseSchema::getKeys() {
  nlohmann::json val = nlohmann::json::object();

  val["vlan"]["name"] = "vlan";
  val["vlan"]["type"] = "key";
  val["vlan"]["simpletype"] = "integer";
  val["vlan"]["description"] = R"POLYCUBE(VLAN identifier)POLYCUBE";
  val["vlan"]["example"] = R"POLYCUBE()POLYCUBE";
  val["address"]["name"] = "address";
  val["address"]["type"] = "key";
  val["address"]["simpletype"] = "string";
  val["address"]["description"] =
      R"POLYCUBE(Address of the filtering database entry)POLYCUBE";
  val["address"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

nlohmann::json FilteringdatabaseSchema::getElements() {
  nlohmann::json val = nlohmann::json::object();

  val["age"]["name"] = "age";
  val["age"]["type"] = "leaf";  // Suppose that type is leaf
  val["age"]["simpletype"] = "integer";
  val["age"]["description"] =
      R"POLYCUBE(Age of the current filtering database entry)POLYCUBE";
  val["age"]["example"] = R"POLYCUBE()POLYCUBE";
  val["age"]["jsonSchema"] = nlohmann::json::parse(R"POLYCUBE({
  "type" : "integer",
  "format" : "uint32",
  "description" : "Age of the current filtering database entry",
  "readOnly" : true
})POLYCUBE");
  val["port"]["name"] = "port";
  val["port"]["type"] = "leaf";  // Suppose that type is leaf
  val["port"]["simpletype"] = "string";
  val["port"]["description"] = R"POLYCUBE(Output port name)POLYCUBE";
  val["port"]["example"] = R"POLYCUBE()POLYCUBE";
  val["port"]["jsonSchema"] = nlohmann::json::parse(R"POLYCUBE({
  "type" : "string",
  "description" : "Output port name"
})POLYCUBE");
  val["entrytype"]["name"] = "entrytype";
  val["entrytype"]["type"] = "leaf";  // Suppose that type is leaf
  val["entrytype"]["simpletype"] = "string";
  val["entrytype"]["description"] =
      R"POLYCUBE(Type of filtering entry)POLYCUBE";
  val["entrytype"]["example"] = R"POLYCUBE()POLYCUBE";
  val["entrytype"]["jsonSchema"] = nlohmann::json::parse(R"POLYCUBE({
  "type" : "string",
  "description" : "Type of filtering entry",
  "enum" : [ "static", "dynamic" ],
  "default" : "static"
})POLYCUBE");

  return val;
}

nlohmann::json FilteringdatabaseSchema::getWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();

  val["port"]["name"] = "port";
  val["port"]["simpletype"] = "string";
  val["port"]["description"] = R"POLYCUBE(Output port name)POLYCUBE";
  val["port"]["example"] = R"POLYCUBE()POLYCUBE";
  val["port"]["jsonSchema"] = nlohmann::json::parse(R"POLYCUBE({
  "type" : "string",
  "description" : "Output port name"
})POLYCUBE");
  val["entrytype"]["name"] = "entrytype";
  val["entrytype"]["simpletype"] = "string";
  val["entrytype"]["description"] =
      R"POLYCUBE(Type of filtering entry)POLYCUBE";
  val["entrytype"]["example"] = R"POLYCUBE()POLYCUBE";
  val["entrytype"]["jsonSchema"] = nlohmann::json::parse(R"POLYCUBE({
  "type" : "string",
  "description" : "Type of filtering entry",
  "enum" : [ "static", "dynamic" ],
  "default" : "static"
})POLYCUBE");

  return val;
}

nlohmann::json FilteringdatabaseSchema::getComplexElements() {
  nlohmann::json val = nlohmann::json::object();

  return val;
}

int32_t FilteringdatabaseSchema::getAge() const {
  return m_Age;
}

void FilteringdatabaseSchema::setAge(int32_t value) {
  m_Age = value;
  m_AgeIsSet = true;
}

bool FilteringdatabaseSchema::ageIsSet() const {
  return m_AgeIsSet;
}

void FilteringdatabaseSchema::unsetAge() {
  m_AgeIsSet = false;
}
int32_t FilteringdatabaseSchema::getVlan() const {
  return m_Vlan;
}

void FilteringdatabaseSchema::setVlan(int32_t value) {
  m_Vlan = value;
  m_VlanIsSet = true;
}

bool FilteringdatabaseSchema::vlanIsSet() const {
  return m_VlanIsSet;
}

void FilteringdatabaseSchema::unsetVlan() {
  m_VlanIsSet = false;
}
std::string FilteringdatabaseSchema::getPort() const {
  return m_Port;
}

void FilteringdatabaseSchema::setPort(std::string value) {
  m_Port = value;
  m_PortIsSet = true;
}

bool FilteringdatabaseSchema::portIsSet() const {
  return m_PortIsSet;
}

void FilteringdatabaseSchema::unsetPort() {
  m_PortIsSet = false;
}
std::string FilteringdatabaseSchema::getAddress() const {
  return m_Address;
}

void FilteringdatabaseSchema::setAddress(std::string value) {
  m_Address = value;
  m_AddressIsSet = true;
}

bool FilteringdatabaseSchema::addressIsSet() const {
  return m_AddressIsSet;
}

void FilteringdatabaseSchema::unsetAddress() {
  m_AddressIsSet = false;
}
std::string FilteringdatabaseSchema::getEntrytype() const {
  return m_Entrytype;
}

void FilteringdatabaseSchema::setEntrytype(std::string value) {
  m_Entrytype = value;
  m_EntrytypeIsSet = true;
}

bool FilteringdatabaseSchema::entrytypeIsSet() const {
  return m_EntrytypeIsSet;
}

void FilteringdatabaseSchema::unsetEntrytype() {
  m_EntrytypeIsSet = false;
}
}
}
}
}
