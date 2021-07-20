
#new_git_repository(
#    name = "github_boost_optional",
#    build_file = "third_party/boost_optional.build",
#    commit = "82acdb9d172e160bae2a5a8a923134565b7d8a4e",
#    remote = "https://github.com/boostorg/optional.git",
#)


cc_library(
    name = "libcrow",
    visibility = ["//visibility:public"],
    srcs = ["crow_all.h"],
    hdrs = ["crow_all.h"],
    deps = [
       "@boost//:algorithm",
       "@boost//:asio",
       "@boost//:optional",
    ],
)
