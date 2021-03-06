/**
* k8switch API
* Kubernetes HyperSwitch Service
*
* OpenAPI spec version: 2.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */

/*
* ServiceBackendInterface.h
*
*
*/

#pragma once

#include "../serializer/ServiceBackendJsonObject.h"


using namespace io::swagger::server::model;

class ServiceBackendInterface {
public:

  virtual void update(const ServiceBackendJsonObject &conf) = 0;
  virtual ServiceBackendJsonObject toJsonObject() = 0;

  /// <summary>
  /// name
  /// </summary>
  virtual std::string getName() = 0;
  virtual void setName(const std::string &value) = 0;

  /// <summary>
  /// IP address of the backend server of the pool
  /// </summary>
  virtual std::string getIp() = 0;

  /// <summary>
  /// Port where the server listen to (this value is ignored in case of ICMP)
  /// </summary>
  virtual uint16_t getPort() = 0;

  /// <summary>
  /// Weight of the backend in the pool
  /// </summary>
  virtual uint16_t getWeight() = 0;
  virtual void setWeight(const uint16_t &value) = 0;
};

