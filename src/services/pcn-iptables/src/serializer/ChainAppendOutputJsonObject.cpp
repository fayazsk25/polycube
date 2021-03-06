/**
* iptables API
* iptables API generated from iptables.yang
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */



#include "ChainAppendOutputJsonObject.h"
#include <regex>

namespace io {
namespace swagger {
namespace server {
namespace model {

ChainAppendOutputJsonObject::ChainAppendOutputJsonObject() {

  m_idIsSet = false;
}

ChainAppendOutputJsonObject::~ChainAppendOutputJsonObject() {}

void ChainAppendOutputJsonObject::validateKeys() {

}

void ChainAppendOutputJsonObject::validateMandatoryFields() {

}

void ChainAppendOutputJsonObject::validateParams() {

}

nlohmann::json ChainAppendOutputJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  if (m_idIsSet) {
    val["id"] = m_id;
  }


  return val;
}

void ChainAppendOutputJsonObject::fromJson(nlohmann::json& val) {
  for(nlohmann::json::iterator it = val.begin(); it != val.end(); ++it) {
    std::string key = it.key();
    bool found = (std::find(allowedParameters_.begin(), allowedParameters_.end(), key) != allowedParameters_.end());
    if (!found) {
      throw std::runtime_error(key + " is not a valid parameter");
      return;
    }
  }

  if (val.find("id") != val.end()) {
    setId(val.at("id"));
  }
}

nlohmann::json ChainAppendOutputJsonObject::helpKeys() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

nlohmann::json ChainAppendOutputJsonObject::helpElements() {
  nlohmann::json val = nlohmann::json::object();

  val["id"]["name"] = "id";
  val["id"]["type"] = "leaf"; // Suppose that type is leaf
  val["id"]["simpletype"] = "integer";
  val["id"]["description"] = R"POLYCUBE()POLYCUBE";
  val["id"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

nlohmann::json ChainAppendOutputJsonObject::helpWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();

  val["id"]["name"] = "id";
  val["id"]["simpletype"] = "integer";
  val["id"]["description"] = R"POLYCUBE()POLYCUBE";
  val["id"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

nlohmann::json ChainAppendOutputJsonObject::helpComplexElements() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

std::vector<std::string> ChainAppendOutputJsonObject::helpActions() {
  std::vector<std::string> val;
  return val;
}

uint32_t ChainAppendOutputJsonObject::getId() const {
  return m_id;
}

void ChainAppendOutputJsonObject::setId(uint32_t value) {
  m_id = value;
  m_idIsSet = true;
}

bool ChainAppendOutputJsonObject::idIsSet() const {
  return m_idIsSet;
}

void ChainAppendOutputJsonObject::unsetId() {
  m_idIsSet = false;
}




}
}
}
}

