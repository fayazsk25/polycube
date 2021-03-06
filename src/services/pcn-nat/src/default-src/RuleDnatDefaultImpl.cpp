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


// These methods have a default implementation. Your are free to keep it or add your own


#include "../RuleDnat.h"



std::shared_ptr<RuleDnatEntry> RuleDnat::getEntry(const uint32_t &id){
  return RuleDnatEntry::getEntry(*this, id);
}

std::vector<std::shared_ptr<RuleDnatEntry>> RuleDnat::getEntryList(){
  return RuleDnatEntry::get(*this);
}

void RuleDnat::addEntry(const uint32_t &id, const RuleDnatEntryJsonObject &conf){
  RuleDnatEntry::create(*this, id, conf);
}

void RuleDnat::addEntryList(const std::vector<RuleDnatEntryJsonObject> &conf){
  for(auto &i : conf){
    uint32_t id_ = i.getId();
    RuleDnatEntry::create(*this, id_,  i);
  }
}

void RuleDnat::replaceEntry(const uint32_t &id, const RuleDnatEntryJsonObject &conf){
  RuleDnatEntry::removeEntry(*this, id);
  uint32_t id_ = conf.getId();
  RuleDnatEntry::create(*this, id_, conf);

}

void RuleDnat::delEntry(const uint32_t &id){
  RuleDnatEntry::removeEntry(*this, id);
}

void RuleDnat::delEntryList(){
  RuleDnatEntry::remove(*this);
}



