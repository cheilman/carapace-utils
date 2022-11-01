#!/usr/bin/env bash

set -euo pipefail

# Run BUILD formatting
bazel run //:buildifier

# Run C++ formatting

# Run C++ linter
bazel build //... --config clang-tidy

