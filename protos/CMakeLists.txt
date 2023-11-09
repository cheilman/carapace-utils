cmake_minimum_required(VERSION 3.20)

project(carapace-utils-protos-lib
        VERSION 0.1.0
        DESCRIPTION "Utilities supporting Carapace"
        HOMEPAGE_URL "https://github.com/cheilman/carapace-utils"
)

#
# Protos
#

set(PROTO_FILES
        helloworld.proto
)

add_library(carapace-utils-protos-lib
        STATIC
        ${PROTO_FILES}
)

target_link_libraries(
        carapace-utils-protos-lib
        PUBLIC
            protobuf::libprotobuf
            grpc
            grpc++
)

target_include_directories(carapace-utils-protos-lib PUBLIC "${CMAKE_BINARY_DIR}")

protobuf_generate(
        TARGET carapace-utils-protos-lib
        LANGUAGE cpp
)
protobuf_generate(
        TARGET carapace-utils-protos-lib
        LANGUAGE grpc
        GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
        PLUGIN "protoc-gen-grpc=\$<TARGET_FILE:grpc_cpp_plugin>"
)


