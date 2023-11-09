cmake_minimum_required(VERSION 3.20)

project(carapace-utils
  VERSION 0.1.0
  DESCRIPTION "Utilities supporting Carapace"
  HOMEPAGE_URL "https://github.com/cheilman/carapace-utils"
)

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# control where libraries and executables are placed during the build.
# with the following settings executables are placed in <the top level of the
# build tree>/bin and libraries/archives in <top level of the build tree>/lib.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")

# disable C and C++ compiler extensions.
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

# include additional cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Let's nicely support folders in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Turn on tests
enable_testing()

# Modules we need
include(FetchContent)

#
# Dependencies
#

set(FETCHCONTENT_QUIET OFF)

# Load protobuf
#FetchContent_Declare(
#        protocolbuffers_protobuf
#        GIT_REPOSITORY https://github.com/protocolbuffers/protobuf.git
#        GIT_TAG v25.0
#        FIND_PACKAGE_ARGS NAMES protobuf
#)
#FetchContent_MakeAvailable(protocolbuffers_protobuf)
#
#include(FindProtobuf)
#find_package(protocolbuffers_protobuf CONFIG REQUIRED)

set(Protobuf_USE_STATIC_LIBS ON)

# gRPC, absl, and protocol buffers
set(ABSL_ENABLE_INSTALL ON)
FetchContent_Declare(
        gRPC
        GIT_REPOSITORY https://github.com/grpc/grpc
        GIT_TAG      v1.59.2
)
FetchContent_MakeAvailable(gRPC)

include(FindProtobuf)
#find_package(protobuf CONFIG REQUIRED)

#
# Protos
#
add_subdirectory(protos)

#
# Libraries
#
#add_subdirectory(src)

#
# Executables
#
#add_subdirectory(apps/dash)
add_subdirectory(apps/greeter)
add_subdirectory(apps/server)

#
# Tests
#
#if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MYPROJECT_BUILD_TESTING) AND BUILD_TESTING)
#  add_subdirectory(tests)
#endif()

