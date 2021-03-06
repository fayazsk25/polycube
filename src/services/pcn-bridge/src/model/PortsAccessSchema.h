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
 * PortsAccessSchema.h
 *
 * vlan associated to a port in access mode
 */

#pragma once

#include "ModelBase.h"

namespace io {
namespace swagger {
namespace server {
namespace model {

/// <summary>
/// vlan associated to a port in access mode
/// </summary>
class PortsAccessSchema : public ModelBase {
 public:
  PortsAccessSchema();
  virtual ~PortsAccessSchema();

  /////////////////////////////////////////////
  /// ModelBase overrides

  void validate() override;

  nlohmann::json toJson() const override;
  void fromJson(nlohmann::json &json) override;

  static nlohmann::json getKeys();
  static nlohmann::json getElements();
  static nlohmann::json getWritableLeafs();
  static nlohmann::json getComplexElements();
  /////////////////////////////////////////////
  /// PortsAccessSchema members

  /// <summary>
  /// VLAN associated with this interface
  /// </summary>
  int32_t getVlanid() const;
  void setVlanid(int32_t value);
  bool vlanidIsSet() const;
  void unsetVlanid();

 protected:
  int32_t m_Vlanid;
  bool m_VlanidIsSet;
};
}
}
}
}
