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


#include "SimpleforwarderApiImpl.h"

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

SimpleforwarderApiImpl::SimpleforwarderApiImpl() {}

/*
* These functions include a default basic implementation.  The user could
* extend adapt this implementation to his needs.
*/

std::shared_ptr<Simpleforwarder> SimpleforwarderApiImpl::get_cube(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  auto iter = cubes.find(name);
  if (iter == cubes.end()) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }

  return iter->second;
}

void SimpleforwarderApiImpl::create_simpleforwarder_by_id(const std::string &name, const SimpleforwarderJsonObject &jsonObject) {
  {
    // check if name is valid before creating it
    std::lock_guard<std::mutex> guard(cubes_mutex);
    if (cubes.count(name) != 0) {
      throw std::runtime_error("There is already a cube with name " + name);
    }
  }
  auto ptr = std::make_shared<Simpleforwarder>(name, jsonObject, jsonObject.getType());
  std::unordered_map<std::string, std::shared_ptr<Simpleforwarder>>::iterator iter;
  bool inserted;

  std::lock_guard<std::mutex> guard(cubes_mutex);
  std::tie(iter, inserted) = cubes.emplace(name, std::move(ptr));

  if (!inserted) {
    throw std::runtime_error("There is already a cube with name " + name);
  }
}

void SimpleforwarderApiImpl::replace_simpleforwarder_by_id(const std::string &name, const SimpleforwarderJsonObject &bridge){
  throw std::runtime_error("Method not supported!");
}

void SimpleforwarderApiImpl::delete_simpleforwarder_by_id(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  if (cubes.count(name) == 0) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }
  cubes.erase(name);
}

std::string SimpleforwarderApiImpl::read_simpleforwarder_uuid_by_id(const std::string &name) {
  auto m = get_cube(name);
  return m->getUuid();
}

std::vector<SimpleforwarderJsonObject> SimpleforwarderApiImpl::read_simpleforwarder_list_by_id() {
  std::vector<SimpleforwarderJsonObject> jsonObject_vect;
  for(auto &i : cubes) {
    auto m = get_cube(i.first);
    jsonObject_vect.push_back(m->toJsonObject());
  }
  return jsonObject_vect;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> SimpleforwarderApiImpl::read_simpleforwarder_list_by_id_get_list() {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  for (auto &x : cubes) {
    nlohmann::fifo_map<std::string, std::string> m;
    m["name"] = x.first;
    r.push_back(std::move(m));
  }
  return r;
}

/*
* Ports list related functions
*/
void SimpleforwarderApiImpl::create_simpleforwarder_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &ports) {
  auto m = get_cube(name);
  m->addPortsList(ports);
}

std::vector<PortsJsonObject> SimpleforwarderApiImpl::read_simpleforwarder_ports_list_by_id(const std::string &name) {
  std::vector<PortsJsonObject> vect;
  auto m = get_cube(name);
  for (auto &i : m->getPortsList()) {
    vect.push_back(i->toJsonObject());
  }
  return vect;
}

void SimpleforwarderApiImpl::replace_simpleforwarder_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &ports) {
  throw std::runtime_error("Method not supported");
}

void SimpleforwarderApiImpl::delete_simpleforwarder_ports_list_by_id(const std::string &name) {
  auto m = get_cube(name);
  m->delPortsList();
}

std::vector<nlohmann::fifo_map<std::string, std::string>> SimpleforwarderApiImpl::read_simpleforwarder_ports_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto m = get_cube(name);
  for(auto &i : m->getPortsList()){
    nlohmann::fifo_map<std::string, std::string> m;
    m["name"] = i->getName();
    r.push_back(std::move(m));
  }
  return r;
}

/*
* Ports related functions
*/
void SimpleforwarderApiImpl::create_simpleforwarder_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &ports) {
  auto m = get_cube(name);
  return m->addPorts(portsName, ports);
}

PortsJsonObject SimpleforwarderApiImpl::read_simpleforwarder_ports_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  return m->getPorts(portsName)->toJsonObject();
}

void SimpleforwarderApiImpl::replace_simpleforwarder_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &ports) {
  auto m = get_cube(name);
  m->replacePorts(portsName, ports);
}

void SimpleforwarderApiImpl::delete_simpleforwarder_ports_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  m->delPorts(portsName);
}

std::string SimpleforwarderApiImpl::read_simpleforwarder_ports_peer_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  auto p = m->getPorts(portsName);
  return p->getPeer();
}

PortsStatusEnum SimpleforwarderApiImpl::read_simpleforwarder_ports_status_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  auto p = m->getPorts(portsName);
  return p->getStatus();
}

std::string SimpleforwarderApiImpl::read_simpleforwarder_ports_uuid_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  auto p = m->getPorts(portsName);
  return p->getUuid();
}

void SimpleforwarderApiImpl::update_simpleforwarder_ports_peer_by_id(const std::string &name, const std::string &portsName, const std::string &peer) {
  auto m = get_cube(name);
  auto p = m->getPorts(portsName);
  p->setPeer(peer);
}


/**
* @brief   Create actions by ID
*
* Create operation of resource: actions*
*
* @param[in] name ID of name
* @param[in] inport ID of inport
* @param[in] value actionsbody object
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::create_simpleforwarder_actions_by_id(const std::string &name, const std::string &inport, const ActionsJsonObject &value) {
  auto simpleforwarder = get_cube(name);

  simpleforwarder->addActions(inport, value);
}




/**
* @brief   Create actions by ID
*
* Create operation of resource: actions*
*
* @param[in] name ID of name
* @param[in] value actionsbody object
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::create_simpleforwarder_actions_list_by_id(const std::string &name, const std::vector<ActionsJsonObject> &value) {
  auto simpleforwarder = get_cube(name);
  simpleforwarder->addActionsList(value);
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> SimpleforwarderApiImpl::create_simpleforwarder_actions_list_by_id_get_list(const std::string &name, const std::vector<ActionsJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&simpleforwarder = get_cube(name);

  auto &&actions = simpleforwarder->addActionsList(value);
  for(auto &i : actions) {
    r.push_back(i->getKeys());
  }
  return r;
}
#endif


/**
* @brief   Delete actions by ID
*
* Delete operation of resource: actions*
*
* @param[in] name ID of name
* @param[in] inport ID of inport
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::delete_simpleforwarder_actions_by_id(const std::string &name, const std::string &inport) {
  auto simpleforwarder = get_cube(name);

  simpleforwarder->delActions(inport);
}




/**
* @brief   Delete actions by ID
*
* Delete operation of resource: actions*
*
* @param[in] name ID of name
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::delete_simpleforwarder_actions_list_by_id(const std::string &name) {
  auto simpleforwarder = get_cube(name);
  simpleforwarder->delActionsList();
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> SimpleforwarderApiImpl::delete_simpleforwarder_actions_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&simpleforwarder = get_cube(name);

  auto &&actions = simpleforwarder->delActionsList();
  for(auto &i : actions) {
    r.push_back(i->getKeys());
  }
  return r;
}
#endif


/**
* @brief   Read action by ID
*
* Read operation of resource: action*
*
* @param[in] name ID of name
* @param[in] inport ID of inport
*
* Responses:
* ActionsActionEnum
*/
ActionsActionEnum
SimpleforwarderApiImpl::read_simpleforwarder_actions_action_by_id(const std::string &name, const std::string &inport) {
  auto simpleforwarder = get_cube(name);
  auto actions = simpleforwarder->getActions(inport);
  return actions->getAction();

}




/**
* @brief   Read actions by ID
*
* Read operation of resource: actions*
*
* @param[in] name ID of name
* @param[in] inport ID of inport
*
* Responses:
* ActionsJsonObject
*/
ActionsJsonObject
SimpleforwarderApiImpl::read_simpleforwarder_actions_by_id(const std::string &name, const std::string &inport) {
  auto simpleforwarder = get_cube(name);
  return simpleforwarder->getActions(inport)->toJsonObject();

}




/**
* @brief   Read actions by ID
*
* Read operation of resource: actions*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<ActionsJsonObject>
*/
std::vector<ActionsJsonObject>
SimpleforwarderApiImpl::read_simpleforwarder_actions_list_by_id(const std::string &name) {
  auto simpleforwarder = get_cube(name);
  auto &&actions = simpleforwarder->getActionsList();
  std::vector<ActionsJsonObject> m;
  for(auto &i : actions)
    m.push_back(i->toJsonObject());
  return m;
}

#define IMPLEMENT_POLYCUBE_GET_LIST

#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> SimpleforwarderApiImpl::read_simpleforwarder_actions_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&simpleforwarder = get_cube(name);

  auto &&actions = simpleforwarder->getActionsList();
  for(auto &i : actions) {
    r.push_back(i->getKeys());
  }
  return r;
}
#endif

#undef IMPLEMENT_POLYCUBE_GET_LIST

/**
* @brief   Read outport by ID
*
* Read operation of resource: outport*
*
* @param[in] name ID of name
* @param[in] inport ID of inport
*
* Responses:
* std::string
*/
std::string
SimpleforwarderApiImpl::read_simpleforwarder_actions_outport_by_id(const std::string &name, const std::string &inport) {
  auto simpleforwarder = get_cube(name);
  auto actions = simpleforwarder->getActions(inport);
  return actions->getOutport();

}




/**
* @brief   Read simpleforwarder by ID
*
* Read operation of resource: simpleforwarder*
*
* @param[in] name ID of name
*
* Responses:
* SimpleforwarderJsonObject
*/
SimpleforwarderJsonObject
SimpleforwarderApiImpl::read_simpleforwarder_by_id(const std::string &name) {
  return get_cube(name)->toJsonObject();

}




/**
* @brief   Read loglevel by ID
*
* Read operation of resource: loglevel*
*
* @param[in] name ID of name
*
* Responses:
* SimpleforwarderLoglevelEnum
*/
SimpleforwarderLoglevelEnum
SimpleforwarderApiImpl::read_simpleforwarder_loglevel_by_id(const std::string &name) {
  auto simpleforwarder = get_cube(name);
  return simpleforwarder->getLoglevel();

}




/**
* @brief   Read type by ID
*
* Read operation of resource: type*
*
* @param[in] name ID of name
*
* Responses:
* CubeType
*/
CubeType
SimpleforwarderApiImpl::read_simpleforwarder_type_by_id(const std::string &name) {
  auto simpleforwarder = get_cube(name);
  return simpleforwarder->getType();

}




/**
* @brief   Replace actions by ID
*
* Replace operation of resource: actions*
*
* @param[in] name ID of name
* @param[in] inport ID of inport
* @param[in] value actionsbody object
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::replace_simpleforwarder_actions_by_id(const std::string &name, const std::string &inport, const ActionsJsonObject &value) {
  auto simpleforwarder = get_cube(name);

  simpleforwarder->replaceActions(inport, value);
}




/**
* @brief   Replace actions by ID
*
* Replace operation of resource: actions*
*
* @param[in] name ID of name
* @param[in] value actionsbody object
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::replace_simpleforwarder_actions_list_by_id(const std::string &name, const std::vector<ActionsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> SimpleforwarderApiImpl::replace_simpleforwarder_actions_list_by_id_get_list(const std::string &name, const std::vector<ActionsJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


/**
* @brief   Update action by ID
*
* Update operation of resource: action*
*
* @param[in] name ID of name
* @param[in] inport ID of inport
* @param[in] value Action associated to the current table entry (i.e., DROP, SLOWPATH, or FORWARD; default: DROP)
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::update_simpleforwarder_actions_action_by_id(const std::string &name, const std::string &inport, const ActionsActionEnum &value) {
  auto simpleforwarder = get_cube(name);
  auto actions = simpleforwarder->getActions(inport);

  actions->setAction(value);
}




/**
* @brief   Update actions by ID
*
* Update operation of resource: actions*
*
* @param[in] name ID of name
* @param[in] inport ID of inport
* @param[in] value actionsbody object
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::update_simpleforwarder_actions_by_id(const std::string &name, const std::string &inport, const ActionsJsonObject &value) {
  auto simpleforwarder = get_cube(name);
  auto actions = simpleforwarder->getActions(inport);

  actions->update(value);
}




/**
* @brief   Update actions by ID
*
* Update operation of resource: actions*
*
* @param[in] name ID of name
* @param[in] value actionsbody object
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::update_simpleforwarder_actions_list_by_id(const std::string &name, const std::vector<ActionsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> SimpleforwarderApiImpl::update_simpleforwarder_actions_list_by_id_get_list(const std::string &name, const std::vector<ActionsJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


/**
* @brief   Update outport by ID
*
* Update operation of resource: outport*
*
* @param[in] name ID of name
* @param[in] inport ID of inport
* @param[in] value Output port (used only when action is FORWARD)
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::update_simpleforwarder_actions_outport_by_id(const std::string &name, const std::string &inport, const std::string &value) {
  auto simpleforwarder = get_cube(name);
  auto actions = simpleforwarder->getActions(inport);

  actions->setOutport(value);
}




/**
* @brief   Update simpleforwarder by ID
*
* Update operation of resource: simpleforwarder*
*
* @param[in] name ID of name
* @param[in] value simpleforwarderbody object
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::update_simpleforwarder_by_id(const std::string &name, const SimpleforwarderJsonObject &value) {
  auto simpleforwarder = get_cube(name);

  simpleforwarder->update(value);
}




/**
* @brief   Update simpleforwarder by ID
*
* Update operation of resource: simpleforwarder*
*
* @param[in] value simpleforwarderbody object
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::update_simpleforwarder_list_by_id(const std::vector<SimpleforwarderJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> SimpleforwarderApiImpl::update_simpleforwarder_list_by_id_get_list(const std::vector<SimpleforwarderJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


/**
* @brief   Update loglevel by ID
*
* Update operation of resource: loglevel*
*
* @param[in] name ID of name
* @param[in] value Defines the logging level of a service instance, from none (OFF) to the most verbose (TRACE)
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::update_simpleforwarder_loglevel_by_id(const std::string &name, const SimpleforwarderLoglevelEnum &value) {
  auto simpleforwarder = get_cube(name);

  simpleforwarder->setLoglevel(value);
}




/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::update_simpleforwarder_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto simpleforwarder = get_cube(name);
  auto ports = simpleforwarder->getPorts(portsName);

  ports->update(value);
}




/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
SimpleforwarderApiImpl::update_simpleforwarder_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> SimpleforwarderApiImpl::update_simpleforwarder_ports_list_by_id_get_list(const std::string &name, const std::vector<PortsJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


}
}
}
}

