load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "carapaced-lib",
  srcs = ["server.cc"],
  deps = [
    "@com_google_absl//absl/strings",
    "@com_github_grpc_grpc//:grpc++",
    "@com_github_grpc_grpc//:grpc++_reflection",
    "//protos:helloworld_cc_grpc",
  ],
)

cc_binary(
  name = "carapaced",
  deps = [
    ":carapaced-lib",
  ],
)

