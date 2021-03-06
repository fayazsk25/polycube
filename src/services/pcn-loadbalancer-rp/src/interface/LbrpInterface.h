/**
* lbrp API
* LoadBalancer Reverse-Proxy Service
*
* OpenAPI spec version: 2.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */

/*
* LbrpInterface.h
*
*
*/

#pragma once

#include "../serializer/LbrpJsonObject.h"

#include "../Ports.h"
#include "../Service.h"
#include "../SrcIpRewrite.h"

using namespace io::swagger::server::model;

class LbrpInterface {
public:

  virtual void update(const LbrpJsonObject &conf) = 0;
  virtual LbrpJsonObject toJsonObject() = 0;

  /// <summary>
  /// Name of the lbrp service
  /// </summary>
  virtual std::string getName() = 0;

  /// <summary>
  /// UUID of the Cube
  /// </summary>
  virtual std::string getUuid() = 0;

  /// <summary>
  /// Type of the Cube (TC, XDP_SKB, XDP_DRV)
  /// </summary>
  virtual CubeType getType() = 0;

  /// <summary>
  /// Defines the logging level of a service instance, from none (OFF) to the most verbose (TRACE)
  /// </summary>
  virtual LbrpLoglevelEnum getLoglevel() = 0;
  virtual void setLoglevel(const LbrpLoglevelEnum &value) = 0;

  /// <summary>
  /// Entry of the ports table
  /// </summary>
  virtual std::shared_ptr<Ports> getPorts(const std::string &name) = 0;
  virtual std::vector<std::shared_ptr<Ports>> getPortsList() = 0;
  virtual void addPorts(const std::string &name, const PortsJsonObject &conf) = 0;
  virtual void addPortsList(const std::vector<PortsJsonObject> &conf) = 0;
  virtual void replacePorts(const std::string &name, const PortsJsonObject &conf) = 0;
  virtual void delPorts(const std::string &name) = 0;
  virtual void delPortsList() = 0;

  /// <summary>
  ///
  /// </summary>
  virtual std::shared_ptr<SrcIpRewrite> getSrcIpRewrite() = 0;
  virtual void addSrcIpRewrite(const SrcIpRewriteJsonObject &value) = 0;
  virtual void replaceSrcIpRewrite(const SrcIpRewriteJsonObject &conf) = 0;
  virtual void delSrcIpRewrite() = 0;

  /// <summary>
  /// Services (i.e., virtual ip:protocol:port) exported to the client
  /// </summary>
  virtual std::shared_ptr<Service> getService(const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto) = 0;
  virtual std::vector<std::shared_ptr<Service>> getServiceList() = 0;
  virtual void addService(const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const ServiceJsonObject &conf) = 0;
  virtual void addServiceList(const std::vector<ServiceJsonObject> &conf) = 0;
  virtual void replaceService(const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const ServiceJsonObject &conf) = 0;
  virtual void delService(const std::string &vip,const uint16_t &vport,const ServiceProtoEnum &proto) = 0;
  virtual void delServiceList() = 0;
};

