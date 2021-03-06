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


/* Do not edit this file manually */

/*
* ActionsInterface.h
*
*
*/

#pragma once

#include "../serializer/ActionsJsonObject.h"


using namespace io::swagger::server::model;

class ActionsInterface {
public:

  virtual void update(const ActionsJsonObject &conf) = 0;
  virtual ActionsJsonObject toJsonObject() = 0;

  /// <summary>
  /// Ingress port
  /// </summary>
  virtual std::string getInport() = 0;

  /// <summary>
  /// Action associated to the current table entry (i.e., DROP, SLOWPATH, or FORWARD; default: DROP)
  /// </summary>
  virtual ActionsActionEnum getAction() = 0;
  virtual void setAction(const ActionsActionEnum &value) = 0;

  /// <summary>
  /// Output port (used only when action is FORWARD)
  /// </summary>
  virtual std::string getOutport() = 0;
  virtual void setOutport(const std::string &value) = 0;
};

