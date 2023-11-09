cmake_minimum_required(VERSION 3.20)

project(carapace-utils-greeter-client
        VERSION 0.1.0
        DESCRIPTION "Utilities supporting Carapace"
        HOMEPAGE_URL "https://github.com/cheilman/carapace-utils"
)

#
# Greeter Server
#

add_executable(carapace-utils-greeter-client
        greeter_client.cc
)

target_link_libraries(carapace-utils-greeter-client carapace-utils-protos-lib)
target_link_libraries(carapace-utils-greeter-client grpc++)