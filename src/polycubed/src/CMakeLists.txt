find_package(PkgConfig REQUIRED)

find_package(Pistache CONFIG REQUIRED)

find_package(OpenSSL REQUIRED)
include_directories(OPENSSL_INCLUDE_DIR)

pkg_check_modules(NL3 libnl-3.0)
pkg_check_modules(NL3GENL libnl-genl-3.0)
pkg_check_modules(NL3ROUTE libnl-route-3.0)

pkg_check_modules(TINS libtins)

include_directories(${NL3_INCLUDE_DIRS})
include_directories(${TINS_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/src/libs/polycube/include)
include_directories(${CMAKE_SOURCE_DIR}/src/libs/spdlog)
include_directories(${CMAKE_SOURCE_DIR}/src/libs/viface)
include_directories(${CMAKE_SOURCE_DIR}/src/libs/bcc/src/cc/)

GET_PROPERTY(LOAD_SERVICES GLOBAL PROPERTY LOAD_SERVICES_)

configure_file(load_services.cpp.in load_services.cpp)
configure_file(version.cpp.in version.cpp)

# this is needed for load_services.cpp that is located under a different folder
include_directories(.)

set(polycubed_sources
  bcc_mutex.cpp
  config.cpp
  polycubed.cpp
  cube_factory_impl.cpp
  dynamic_library.cpp
  management_lib.cpp
  polycubed_core.cpp
  rest_server.cpp
  port.cpp
  port_tc.cpp
  port_xdp.cpp
  cube.cpp
  cube_tc.cpp
  cube_xdp.cpp
  controller.cpp
  port_host.cpp
  extiface_tc.cpp
  extiface_xdp.cpp
  extiface_info.cpp
  netlink.cpp
  service_controller.cpp
  patchpanel.cpp
  datapath_log.cpp
  utils.cpp
  id_generator.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/load_services.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/version.cpp)

add_executable(polycubed
  ${polycubed_sources})

set(polycubed_libraries
  polycube
  uuid
  viface
  dl
  pistache
  pthread
  bcc-static
  ${OPENSSL_LIBRARIES}
  ${NL3_LIBRARIES}
  ${NL3ROUTE_LIBRARIES}
  ${NL3GENL_LIBRARIES}
  ${TINS_LIBRARIES}
)

if (HAVE_POLYCUBE_TOOLS)
  set (polycubed_libraries ${polycubed_libraries} polycube-tools)
endif (HAVE_POLYCUBE_TOOLS)

target_link_libraries(polycubed
  ${polycubed_libraries})

# for now install the binary directly, later on we could create a folder with
# the binary and all the resources
install (TARGETS polycubed DESTINATION bin)

# create /var/log/polycube and give permissions to this user
install(CODE
"execute_process( COMMAND /bin/sh -c \"mkdir -p /var/log/polycube && chown $ENV{USER} /var/log/polycube \")")

