include(${PROJECT_SOURCE_DIR}/cmake/LoadFileAsVariable.cmake)

aux_source_directory(serializer SERIALIZER_SOURCES)
aux_source_directory(api API_SOURCES)
aux_source_directory(default-src SRC_SOURCES)

include_directories(serializer)
include_directories(interface)
include_directories(default-src)

# Needed to load files as variables
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(pcn-nat SHARED
  ${SERIALIZER_SOURCES}
  ${API_SOURCES}
  ${SRC_SOURCES}
  NattingTable.cpp
  Ports.cpp
  Rule.cpp
  RuleDnat.cpp
  RuleDnatEntry.cpp
  RuleMasquerade.cpp
  RulePortForwarding.cpp
  RulePortForwardingEntry.cpp
  RuleSnat.cpp
  RuleSnatEntry.cpp
  Nat.cpp
  Nat-lib.cpp)

# load ebpf datapath code in std::string variables
load_file_as_variable(pcn-nat Nat_dp.c nat_code)

target_link_libraries(pcn-nat
  polycube
  uuid)

# Specify shared library install directory

set(CMAKE_INSTALL_LIBDIR /usr/lib)

install(
    TARGETS
    pcn-nat
    DESTINATION
    "${CMAKE_INSTALL_LIBDIR}"
)
