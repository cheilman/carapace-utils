cmake_minimum_required(VERSION 3.20)

project(carapace-utils-protos-lib
        VERSION 0.1.0
        DESCRIPTION "Utilities supporting Carapace"
        HOMEPAGE_URL "https://github.com/cheilman/carapace-utils"
)

#
# Protos
#

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS helloworld.proto)

add_library(carapace-utils-protos-lib
        STATIC
        ${PROTO_SRCS} ${PROTO_HDRS}
)

target_link_libraries(carapace-utils-protos-lib PUBLIC protobuf::libprotobuf)

target_include_directories(carapace-utils-protos-lib PUBLIC ${Protobuf_HEADERS})


