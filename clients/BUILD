
cc_library(
  name = "greeter_client-lib",
  srcs = ["greeter_client.cc"],
  deps = [
    "@com_github_grpc_grpc//:grpc++",
    "//protos:helloworld_cc_grpc",
  ],
)

cc_binary(
  name = "greeter_client",
  deps = [":greeter_client-lib"],
)

