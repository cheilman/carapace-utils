load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "carapaced-lib",
  srcs = ["main.cc"],
  deps = ["@com_google_absl//absl/strings"],
)

cc_binary(
  name = "carapaced",
  deps = [
    ":carapaced-lib",
  ],
)

