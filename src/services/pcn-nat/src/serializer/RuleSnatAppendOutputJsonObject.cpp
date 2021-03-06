/**
* nat API
* NAT Service
*
* OpenAPI spec version: 1.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */



#include "RuleSnatAppendOutputJsonObject.h"
#include <regex>

namespace io {
namespace swagger {
namespace server {
namespace model {

RuleSnatAppendOutputJsonObject::RuleSnatAppendOutputJsonObject() {

  m_idIsSet = false;
}

RuleSnatAppendOutputJsonObject::~RuleSnatAppendOutputJsonObject() {}

void RuleSnatAppendOutputJsonObject::validateKeys() {

}

void RuleSnatAppendOutputJsonObject::validateMandatoryFields() {

}

void RuleSnatAppendOutputJsonObject::validateParams() {

}

nlohmann::json RuleSnatAppendOutputJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  if (m_idIsSet) {
    val["id"] = m_id;
  }


  return val;
}

void RuleSnatAppendOutputJsonObject::fromJson(nlohmann::json& val) {
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

nlohmann::json RuleSnatAppendOutputJsonObject::helpKeys() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

nlohmann::json RuleSnatAppendOutputJsonObject::helpElements() {
  nlohmann::json val = nlohmann::json::object();

  val["id"]["name"] = "id";
  val["id"]["type"] = "leaf"; // Suppose that type is leaf
  val["id"]["simpletype"] = "integer";
  val["id"]["description"] = R"POLYCUBE()POLYCUBE";
  val["id"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

nlohmann::json RuleSnatAppendOutputJsonObject::helpWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();

  val["id"]["name"] = "id";
  val["id"]["simpletype"] = "integer";
  val["id"]["description"] = R"POLYCUBE()POLYCUBE";
  val["id"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

nlohmann::json RuleSnatAppendOutputJsonObject::helpComplexElements() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

std::vector<std::string> RuleSnatAppendOutputJsonObject::helpActions() {
  std::vector<std::string> val;
  return val;
}

uint32_t RuleSnatAppendOutputJsonObject::getId() const {
  return m_id;
}

void RuleSnatAppendOutputJsonObject::setId(uint32_t value) {
  m_id = value;
  m_idIsSet = true;
}

bool RuleSnatAppendOutputJsonObject::idIsSet() const {
  return m_idIsSet;
}

void RuleSnatAppendOutputJsonObject::unsetId() {
  m_idIsSet = false;
}




}
}
}
}

