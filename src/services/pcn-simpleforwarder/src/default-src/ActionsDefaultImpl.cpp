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


// These methods have a default implementation. Your are free to keep it or add your own


#include "../Actions.h"


nlohmann::fifo_map<std::string, std::string>  Actions::getKeys() {
  nlohmann::fifo_map<std::string, std::string>  r;

  r["inport"] = getInport();

  return r;
}







