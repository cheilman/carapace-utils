load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

#
# Go toolchain
#

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "io_bazel_rules_go",
  sha256 = "099a9fb96a376ccbbb7d291ed4ecbdfd42f6bc822ab77ae6f1b5cb9e914e94fa",
  urls = [
    "https://mirror.bazel.build/github.com/bazelbuild/rules_go/releases/download/v0.35.0/rules_go-v0.35.0.zip",
    "https://github.com/bazelbuild/rules_go/releases/download/v0.35.0/rules_go-v0.35.0.zip",
  ],
)

load("@io_bazel_rules_go//go:deps.bzl", "go_register_toolchains", "go_rules_dependencies")

go_rules_dependencies()
go_register_toolchains(version = "1.19.1")

#
# Protocol Buffers
#

# rules_cc defines rules for generating C++ code from Protocol Buffers.
http_archive(
  name = "rules_cc",
  sha256 = "35f2fb4ea0b3e61ad64a369de284e4fbbdcdba71836a5555abb5e194cf119509",
  strip_prefix = "rules_cc-624b5d59dfb45672d4239422fa1e3de1822ee110",
  urls = [
    "https://mirror.bazel.build/github.com/bazelbuild/rules_cc/archive/624b5d59dfb45672d4239422fa1e3de1822ee110.tar.gz",
    "https://github.com/bazelbuild/rules_cc/archive/624b5d59dfb45672d4239422fa1e3de1822ee110.tar.gz",
  ],
)

# rules_proto defines abstract rules for building Protocol Buffers.
http_archive(
  name = "rules_proto",
  sha256 = "2490dca4f249b8a9a3ab07bd1ba6eca085aaf8e45a734af92aad0c42d9dc7aaf",
  strip_prefix = "rules_proto-218ffa7dfa5408492dc86c01ee637614f8695c45",
  urls = [
    "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/218ffa7dfa5408492dc86c01ee637614f8695c45.tar.gz",
    "https://github.com/bazelbuild/rules_proto/archive/218ffa7dfa5408492dc86c01ee637614f8695c45.tar.gz",
  ],
)

load("@rules_cc//cc:repositories.bzl", "rules_cc_dependencies")
rules_cc_dependencies()

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

#
# Abseil (and skylib dependency)
#

http_archive(
  name = "bazel_skylib",
  urls = [
    "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.3.0/bazel-skylib-1.3.0.tar.gz",
    "https://github.com/bazelbuild/bazel-skylib/releases/download/1.3.0/bazel-skylib-1.3.0.tar.gz",
  ],
  sha256 = "74d544d96f4a5bb630d465ca8bbcfe231e3594e5aae57e1edbf17a6eb3ca2506",
)
load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
bazel_skylib_workspace()

http_archive(
  name = "com_google_absl",
  urls = ["https://github.com/abseil/abseil-cpp/archive/85cc4947dbec515868e47a7e4e2b604b21e333cb.zip"],
  strip_prefix = "abseil-cpp-85cc4947dbec515868e47a7e4e2b604b21e333cb",
  sha256 = "09001d35f07667c6ca2e75438d02e96839e21d71960d9ea90127a6188a49dc33",
)

#
# gRPC
#

http_archive(
  name = "com_github_grpc_grpc",
  patch_args = ["-p1"],
  patches = ["//tools:ignore_version_in_go_register_toolchains.patch"],
  sha256 = "76900ab068da86378395a8e125b5cc43dfae671e09ff6462ddfef18676e2165a",
  strip_prefix = "grpc-1.50.0",
  urls = ["https://github.com/grpc/grpc/archive/v1.50.0.tar.gz"],
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()
