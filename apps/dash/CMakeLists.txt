cmake_minimum_required(VERSION 3.20)

#
# Dependencies
#

include(FetchContent)

FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
  GIT_PROGRESS TRUE
  GIT_SHALLOW FALSE
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

#
# Project
#

project(
  carapace-dash
  VERSION 0.1.0
  DESCRIPTION "Dashboard supporting carapace"
  HOMEPAGE_URL "https://github.com/cheilman/carapace-utils"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
  carapace-dash
  carapace_dash.cc
)

target_link_libraries(
  carapace-dash
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)

set_target_properties(
  carapace-dash
  PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-warnings-as-errors=*"
)

target_include_directories(
  carapace-dash
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
)

target_include_directories(
  carapace-dash
  SYSTEM
  INTERFACE $<INSTALL_INTERFACE:include>
)

target_compile_features(
  carapace-dash
  PUBLIC cxx_std_17
)

target_compile_options(carapace-dash PRIVATE "-Wall")
target_compile_options(carapace-dash PRIVATE "-Wextra")
target_compile_options(carapace-dash PRIVATE "-pedantic")
target_compile_options(carapace-dash PRIVATE "-Werror")
target_compile_options(carapace-dash PRIVATE "-Wmissing-declarations")
target_compile_options(carapace-dash PRIVATE "-Wshadow")

