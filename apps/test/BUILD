load("@rules_cc//cc:defs.bzl", "cc_library")

cc_test(
    name = "test",
    srcs = ["src/TestServer.cpp"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:main",
        "//third_party/Config:libconfig"
    ],
)