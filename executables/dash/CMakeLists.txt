cmake_minimum_required(VERSION 3.20)

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


