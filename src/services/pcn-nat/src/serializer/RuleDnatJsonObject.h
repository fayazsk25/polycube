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

/*
* RuleDnatJsonObject.h
*
*
*/

#pragma once


#include "JsonObjectBase.h"

#include "RuleDnatEntryJsonObject.h"
#include <vector>

namespace io {
namespace swagger {
namespace server {
namespace model {


/// <summary>
///
/// </summary>
class  RuleDnatJsonObject : public JsonObjectBase {
public:
  RuleDnatJsonObject();
  virtual ~RuleDnatJsonObject();

  /////////////////////////////////////////////
  /// JsonObjectBase overrides

  void validateKeys() override;
  void validateMandatoryFields() override;
  void validateParams() override;

  nlohmann::json toJson() const override;
  void fromJson(nlohmann::json& json) override;

  static nlohmann::json helpKeys();
  static nlohmann::json helpElements();
  static nlohmann::json helpWritableLeafs();
  static nlohmann::json helpComplexElements();
  static std::vector<std::string> helpActions();
  /////////////////////////////////////////////
  /// RuleDnatJsonObject members

  /// <summary>
  /// List of Destination NAT rules
  /// </summary>
  const std::vector<RuleDnatEntryJsonObject>& getEntry() const;
  void addRuleDnatEntry(RuleDnatEntryJsonObject value);
  bool entryIsSet() const;
  void unsetEntry();


protected:
  std::vector<RuleDnatEntryJsonObject> m_entry;
  bool m_entryIsSet;

  std::vector<std::string> allowedParameters_{ "entry" };
};

}
}
}
}

