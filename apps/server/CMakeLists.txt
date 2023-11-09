cmake_minimum_required(VERSION 3.20)

project(carapace-utils-greeter-server
        VERSION 0.1.0
        DESCRIPTION "Utilities supporting Carapace"
        HOMEPAGE_URL "https://github.com/cheilman/carapace-utils"
)

#
# Greeter Server
#

add_executable(carapace-utils-greeter-server
        server.cc
        termcolor.hpp
)

target_link_libraries(carapace-utils-greeter-server carapace-utils-protos-lib)
target_link_libraries(carapace-utils-greeter-server grpc++ grpc++_reflection)
