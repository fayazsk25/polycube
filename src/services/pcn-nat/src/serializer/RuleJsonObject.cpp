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



#include "RuleJsonObject.h"
#include <regex>

namespace io {
namespace swagger {
namespace server {
namespace model {

RuleJsonObject::RuleJsonObject() {

  m_snatIsSet = false;

  m_masqueradeIsSet = false;

  m_dnatIsSet = false;

  m_portForwardingIsSet = false;
}

RuleJsonObject::~RuleJsonObject() {}

void RuleJsonObject::validateKeys() {

}

void RuleJsonObject::validateMandatoryFields() {

}

void RuleJsonObject::validateParams() {

}

nlohmann::json RuleJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  if (m_snatIsSet) {
    val["snat"] = JsonObjectBase::toJson(m_snat);
  }
  if (m_masqueradeIsSet) {
    val["masquerade"] = JsonObjectBase::toJson(m_masquerade);
  }
  if (m_dnatIsSet) {
    val["dnat"] = JsonObjectBase::toJson(m_dnat);
  }
  if (m_portForwardingIsSet) {
    val["port-forwarding"] = JsonObjectBase::toJson(m_portForwarding);
  }

  return val;
}

void RuleJsonObject::fromJson(nlohmann::json& val) {
  for(nlohmann::json::iterator it = val.begin(); it != val.end(); ++it) {
    std::string key = it.key();
    bool found = (std::find(allowedParameters_.begin(), allowedParameters_.end(), key) != allowedParameters_.end());
    if (!found) {
      throw std::runtime_error(key + " is not a valid parameter");
      return;
    }
  }

  if (val.find("snat") != val.end()) {


    if (!val["snat"].is_null()) {
      RuleSnatJsonObject newItem;
      newItem.fromJson(val["snat"]);
      setSnat(newItem);
    }
  }

  if (val.find("masquerade") != val.end()) {


    if (!val["masquerade"].is_null()) {
      RuleMasqueradeJsonObject newItem;
      newItem.fromJson(val["masquerade"]);
      setMasquerade(newItem);
    }
  }

  if (val.find("dnat") != val.end()) {


    if (!val["dnat"].is_null()) {
      RuleDnatJsonObject newItem;
      newItem.fromJson(val["dnat"]);
      setDnat(newItem);
    }
  }

  if (val.find("port-forwarding") != val.end()) {


    if (!val["port-forwarding"].is_null()) {
      RulePortForwardingJsonObject newItem;
      newItem.fromJson(val["port-forwarding"]);
      setPortForwarding(newItem);
    }
  }
}

nlohmann::json RuleJsonObject::helpKeys() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

nlohmann::json RuleJsonObject::helpElements() {
  nlohmann::json val = nlohmann::json::object();

  val["snat"]["name"] = "snat";
  val["snat"]["type"] = "leaf"; // Suppose that type is leaf
  val["snat"]["description"] = R"POLYCUBE()POLYCUBE";
  val["snat"]["example"] = R"POLYCUBE()POLYCUBE";
  val["masquerade"]["name"] = "masquerade";
  val["masquerade"]["type"] = "leaf"; // Suppose that type is leaf
  val["masquerade"]["description"] = R"POLYCUBE()POLYCUBE";
  val["masquerade"]["example"] = R"POLYCUBE()POLYCUBE";
  val["dnat"]["name"] = "dnat";
  val["dnat"]["type"] = "leaf"; // Suppose that type is leaf
  val["dnat"]["description"] = R"POLYCUBE()POLYCUBE";
  val["dnat"]["example"] = R"POLYCUBE()POLYCUBE";
  val["port-forwarding"]["name"] = "port-forwarding";
  val["port-forwarding"]["type"] = "leaf"; // Suppose that type is leaf
  val["port-forwarding"]["description"] = R"POLYCUBE()POLYCUBE";
  val["port-forwarding"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

nlohmann::json RuleJsonObject::helpWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

nlohmann::json RuleJsonObject::helpComplexElements() {
  nlohmann::json val = nlohmann::json::object();

  val["snat"]["name"] = "snat";
  val["snat"]["type"] = "complex";
  val["snat"]["description"] = R"POLYCUBE()POLYCUBE";
  val["snat"]["example"] = R"POLYCUBE()POLYCUBE";
  val["masquerade"]["name"] = "masquerade";
  val["masquerade"]["type"] = "complex";
  val["masquerade"]["description"] = R"POLYCUBE()POLYCUBE";
  val["masquerade"]["example"] = R"POLYCUBE()POLYCUBE";
  val["dnat"]["name"] = "dnat";
  val["dnat"]["type"] = "complex";
  val["dnat"]["description"] = R"POLYCUBE()POLYCUBE";
  val["dnat"]["example"] = R"POLYCUBE()POLYCUBE";
  val["port-forwarding"]["name"] = "port-forwarding";
  val["port-forwarding"]["type"] = "complex";
  val["port-forwarding"]["description"] = R"POLYCUBE()POLYCUBE";
  val["port-forwarding"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

std::vector<std::string> RuleJsonObject::helpActions() {
  std::vector<std::string> val;
  return val;
}

RuleSnatJsonObject RuleJsonObject::getSnat() const {
  return m_snat;
}

void RuleJsonObject::setSnat(RuleSnatJsonObject value) {
  m_snat = value;
  m_snatIsSet = true;
}

bool RuleJsonObject::snatIsSet() const {
  return m_snatIsSet;
}

void RuleJsonObject::unsetSnat() {
  m_snatIsSet = false;
}



RuleMasqueradeJsonObject RuleJsonObject::getMasquerade() const {
  return m_masquerade;
}

void RuleJsonObject::setMasquerade(RuleMasqueradeJsonObject value) {
  m_masquerade = value;
  m_masqueradeIsSet = true;
}

bool RuleJsonObject::masqueradeIsSet() const {
  return m_masqueradeIsSet;
}

void RuleJsonObject::unsetMasquerade() {
  m_masqueradeIsSet = false;
}



RuleDnatJsonObject RuleJsonObject::getDnat() const {
  return m_dnat;
}

void RuleJsonObject::setDnat(RuleDnatJsonObject value) {
  m_dnat = value;
  m_dnatIsSet = true;
}

bool RuleJsonObject::dnatIsSet() const {
  return m_dnatIsSet;
}

void RuleJsonObject::unsetDnat() {
  m_dnatIsSet = false;
}



RulePortForwardingJsonObject RuleJsonObject::getPortForwarding() const {
  return m_portForwarding;
}

void RuleJsonObject::setPortForwarding(RulePortForwardingJsonObject value) {
  m_portForwarding = value;
  m_portForwardingIsSet = true;
}

bool RuleJsonObject::portForwardingIsSet() const {
  return m_portForwardingIsSet;
}

void RuleJsonObject::unsetPortForwarding() {
  m_portForwardingIsSet = false;
}




}
}
}
}

