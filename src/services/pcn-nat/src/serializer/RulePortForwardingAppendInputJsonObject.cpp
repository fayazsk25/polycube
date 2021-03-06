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



#include "RulePortForwardingAppendInputJsonObject.h"
#include <regex>

namespace io {
namespace swagger {
namespace server {
namespace model {

RulePortForwardingAppendInputJsonObject::RulePortForwardingAppendInputJsonObject() {

  m_externalIpIsSet = false;

  m_externalPortIsSet = false;

  m_protoIsSet = false;

  m_internalIpIsSet = false;

  m_internalPortIsSet = false;
}

RulePortForwardingAppendInputJsonObject::~RulePortForwardingAppendInputJsonObject() {}

void RulePortForwardingAppendInputJsonObject::validateKeys() {

}

void RulePortForwardingAppendInputJsonObject::validateMandatoryFields() {

  if (!m_externalIpIsSet) {
    throw std::runtime_error("Variable external-ip is required");
  }
  if (!m_externalPortIsSet) {
    throw std::runtime_error("Variable external-port is required");
  }
  if (!m_internalIpIsSet) {
    throw std::runtime_error("Variable internal-ip is required");
  }
  if (!m_internalPortIsSet) {
    throw std::runtime_error("Variable internal-port is required");
  }
}

void RulePortForwardingAppendInputJsonObject::validateParams() {

  if (m_externalIpIsSet) {
    std::string patter_value = R"PATTERN((([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])(%[\p{N}\p{L}]+)?)PATTERN";
    std::regex e (patter_value);
    if (!std::regex_match(m_externalIp, e))
      throw std::runtime_error("Variable external-ip has not a valid format");
  }
  if (m_externalPortIsSet) {
    if (m_externalPort < 0 || m_externalPort > 65535) {
      throw std::runtime_error("Variable external-port is not in the range");
    }
  }
  if (m_internalIpIsSet) {
    std::string patter_value = R"PATTERN((([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])(%[\p{N}\p{L}]+)?)PATTERN";
    std::regex e (patter_value);
    if (!std::regex_match(m_internalIp, e))
      throw std::runtime_error("Variable internal-ip has not a valid format");
  }
  if (m_internalPortIsSet) {
    if (m_internalPort < 0 || m_internalPort > 65535) {
      throw std::runtime_error("Variable internal-port is not in the range");
    }
  }
}

nlohmann::json RulePortForwardingAppendInputJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  val["external-ip"] = m_externalIp;
  val["external-port"] = m_externalPort;
  if (m_protoIsSet) {
    val["proto"] = m_proto;
  }

  val["internal-ip"] = m_internalIp;
  val["internal-port"] = m_internalPort;

  return val;
}

void RulePortForwardingAppendInputJsonObject::fromJson(nlohmann::json& val) {
  for(nlohmann::json::iterator it = val.begin(); it != val.end(); ++it) {
    std::string key = it.key();
    bool found = (std::find(allowedParameters_.begin(), allowedParameters_.end(), key) != allowedParameters_.end());
    if (!found) {
      throw std::runtime_error(key + " is not a valid parameter");
      return;
    }
  }

  if (val.find("external-ip") != val.end()) {
    setExternalIp(val.at("external-ip"));
  }

  if (val.find("external-port") != val.end()) {
    setExternalPort(val.at("external-port"));
  }

  if (val.find("proto") != val.end()) {
    setProto(val.at("proto"));
  }

  if (val.find("internal-ip") != val.end()) {
    setInternalIp(val.at("internal-ip"));
  }

  if (val.find("internal-port") != val.end()) {
    setInternalPort(val.at("internal-port"));
  }
}

nlohmann::json RulePortForwardingAppendInputJsonObject::helpKeys() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

nlohmann::json RulePortForwardingAppendInputJsonObject::helpElements() {
  nlohmann::json val = nlohmann::json::object();

  val["external-ip"]["name"] = "external-ip";
  val["external-ip"]["type"] = "leaf"; // Suppose that type is leaf
  val["external-ip"]["simpletype"] = "string";
  val["external-ip"]["description"] = R"POLYCUBE(External destination IP address)POLYCUBE";
  val["external-ip"]["example"] = R"POLYCUBE(8.8.8.8)POLYCUBE";
  val["external-port"]["name"] = "external-port";
  val["external-port"]["type"] = "leaf"; // Suppose that type is leaf
  val["external-port"]["simpletype"] = "integer";
  val["external-port"]["description"] = R"POLYCUBE(External destination L4 port)POLYCUBE";
  val["external-port"]["example"] = R"POLYCUBE()POLYCUBE";
  val["proto"]["name"] = "proto";
  val["proto"]["type"] = "leaf"; // Suppose that type is leaf
  val["proto"]["simpletype"] = "string";
  val["proto"]["description"] = R"POLYCUBE(L4 protocol (TCP, UDP, ALL))POLYCUBE";
  val["proto"]["example"] = R"POLYCUBE()POLYCUBE";
  val["internal-ip"]["name"] = "internal-ip";
  val["internal-ip"]["type"] = "leaf"; // Suppose that type is leaf
  val["internal-ip"]["simpletype"] = "string";
  val["internal-ip"]["description"] = R"POLYCUBE(Internal destination IP address)POLYCUBE";
  val["internal-ip"]["example"] = R"POLYCUBE(10.0.0.1)POLYCUBE";
  val["internal-port"]["name"] = "internal-port";
  val["internal-port"]["type"] = "leaf"; // Suppose that type is leaf
  val["internal-port"]["simpletype"] = "integer";
  val["internal-port"]["description"] = R"POLYCUBE(Internal destination L4 port)POLYCUBE";
  val["internal-port"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

nlohmann::json RulePortForwardingAppendInputJsonObject::helpWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();

  val["external-ip"]["name"] = "external-ip";
  val["external-ip"]["simpletype"] = "string";
  val["external-ip"]["description"] = R"POLYCUBE(External destination IP address)POLYCUBE";
  val["external-ip"]["example"] = R"POLYCUBE(8.8.8.8)POLYCUBE";
  val["external-port"]["name"] = "external-port";
  val["external-port"]["simpletype"] = "integer";
  val["external-port"]["description"] = R"POLYCUBE(External destination L4 port)POLYCUBE";
  val["external-port"]["example"] = R"POLYCUBE()POLYCUBE";
  val["proto"]["name"] = "proto";
  val["proto"]["simpletype"] = "string";
  val["proto"]["description"] = R"POLYCUBE(L4 protocol (TCP, UDP, ALL))POLYCUBE";
  val["proto"]["example"] = R"POLYCUBE()POLYCUBE";
  val["internal-ip"]["name"] = "internal-ip";
  val["internal-ip"]["simpletype"] = "string";
  val["internal-ip"]["description"] = R"POLYCUBE(Internal destination IP address)POLYCUBE";
  val["internal-ip"]["example"] = R"POLYCUBE(10.0.0.1)POLYCUBE";
  val["internal-port"]["name"] = "internal-port";
  val["internal-port"]["simpletype"] = "integer";
  val["internal-port"]["description"] = R"POLYCUBE(Internal destination L4 port)POLYCUBE";
  val["internal-port"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

nlohmann::json RulePortForwardingAppendInputJsonObject::helpComplexElements() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

std::vector<std::string> RulePortForwardingAppendInputJsonObject::helpActions() {
  std::vector<std::string> val;
  return val;
}

std::string RulePortForwardingAppendInputJsonObject::getExternalIp() const {
  return m_externalIp;
}

void RulePortForwardingAppendInputJsonObject::setExternalIp(std::string value) {
  m_externalIp = value;
  m_externalIpIsSet = true;
}

bool RulePortForwardingAppendInputJsonObject::externalIpIsSet() const {
  return m_externalIpIsSet;
}

void RulePortForwardingAppendInputJsonObject::unsetExternalIp() {
  m_externalIpIsSet = false;
}



uint16_t RulePortForwardingAppendInputJsonObject::getExternalPort() const {
  return m_externalPort;
}

void RulePortForwardingAppendInputJsonObject::setExternalPort(uint16_t value) {
  m_externalPort = value;
  m_externalPortIsSet = true;
}

bool RulePortForwardingAppendInputJsonObject::externalPortIsSet() const {
  return m_externalPortIsSet;
}

void RulePortForwardingAppendInputJsonObject::unsetExternalPort() {
  m_externalPortIsSet = false;
}



std::string RulePortForwardingAppendInputJsonObject::getProto() const {
  return m_proto;
}

void RulePortForwardingAppendInputJsonObject::setProto(std::string value) {
  m_proto = value;
  m_protoIsSet = true;
}

bool RulePortForwardingAppendInputJsonObject::protoIsSet() const {
  return m_protoIsSet;
}

void RulePortForwardingAppendInputJsonObject::unsetProto() {
  m_protoIsSet = false;
}



std::string RulePortForwardingAppendInputJsonObject::getInternalIp() const {
  return m_internalIp;
}

void RulePortForwardingAppendInputJsonObject::setInternalIp(std::string value) {
  m_internalIp = value;
  m_internalIpIsSet = true;
}

bool RulePortForwardingAppendInputJsonObject::internalIpIsSet() const {
  return m_internalIpIsSet;
}

void RulePortForwardingAppendInputJsonObject::unsetInternalIp() {
  m_internalIpIsSet = false;
}



uint16_t RulePortForwardingAppendInputJsonObject::getInternalPort() const {
  return m_internalPort;
}

void RulePortForwardingAppendInputJsonObject::setInternalPort(uint16_t value) {
  m_internalPort = value;
  m_internalPortIsSet = true;
}

bool RulePortForwardingAppendInputJsonObject::internalPortIsSet() const {
  return m_internalPortIsSet;
}

void RulePortForwardingAppendInputJsonObject::unsetInternalPort() {
  m_internalPortIsSet = false;
}




}
}
}
}

