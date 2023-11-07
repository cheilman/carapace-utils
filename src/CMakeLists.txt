cmake_minimum_required(VERSION 3.20)

project(carapace-utils-lib
  VERSION 0.1.0
  DESCRIPTION "Utilities supporting Carapace"
  HOMEPAGE_URL "https://github.com/cheilman/carapace-utils"
)

#
# Library
#

set(HEADER_LIST "${carapace-utils_SOURCE_DIR}/include/carapace-utils/base_module.h")

add_library(carapace-utils-lib
  base_module.cpp
  ${HEADER_LIST}
)

target_include_directories(carapace-utils-lib PUBLIC ../include)

target_compile_features(carapace-utils-lib PUBLIC cxx_std_17)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST}
)


