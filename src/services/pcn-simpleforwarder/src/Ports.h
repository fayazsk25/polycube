/**
* simpleforwarder API
* Simple Forwarder Base Service
*
* OpenAPI spec version: 2.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/

#pragma once

#include "../interface/PortsInterface.h"

#include "polycube/services/cube.h"
#include "polycube/services/fifo_map.hpp"
#include "polycube/services/port.h"
#include "polycube/services/utils.h"

#include <spdlog/spdlog.h>

class Simpleforwarder;

using namespace io::swagger::server::model;

class Ports : public polycube::service::Port, public PortsInterface {
 public:
  Ports(polycube::service::Cube<Ports> &parent,
        std::shared_ptr<polycube::service::PortIface> port,
        const PortsJsonObject &conf);
  virtual ~Ports();

  static void create(Simpleforwarder &parent, const std::string &name,
                     const PortsJsonObject &conf);
  static std::shared_ptr<Ports> getEntry(Simpleforwarder &parent,
                                         const std::string &name);
  static void removeEntry(Simpleforwarder &parent, const std::string &name);
  static std::vector<std::shared_ptr<Ports>> get(Simpleforwarder &parent);
  static void remove(Simpleforwarder &parent);
  nlohmann::fifo_map<std::string, std::string> getKeys();
  std::shared_ptr<spdlog::logger> logger();
  void update(const PortsJsonObject &conf) override;
  PortsJsonObject toJsonObject() override;

  /// <summary>
  /// Port Name
  /// </summary>
  std::string getName() override;

  /// <summary>
  /// UUID of the port
  /// </summary>
  std::string getUuid() override;

  /// <summary>
  /// Status of the port (UP or DOWN)
  /// </summary>
  PortsStatusEnum getStatus() override;

  /// <summary>
  /// Peer name, such as a network interfaces (e.g., &#39;veth0&#39;) or another
  /// cube (e.g., &#39;br1:port2&#39;)
  /// </summary>
  std::string getPeer() override;
  void setPeer(const std::string &value) override;

 private:
  Simpleforwarder &parent_;
};
