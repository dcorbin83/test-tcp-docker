load("@bazel_tools//tools/build_defs/repo:http.bzl","http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl","maybe")

#cc_deps
BOOST_VERSION = "1_67_0"

def cc_deps():
    maybe(
        http_archive,
        name = "boost",
        build_file = "@//third_party:BUILD.boost",
        sha256 = "2684c972994ee57fc5632e03bf044746f6eb45d4920c343937a465fd67a5adba",
        strip_prefix = "boost_%s" % BOOST_VERSION,
        urls = [
            "http://dl.bintray.com/boostorg/release/1.67.0/source/boost_%s.tar.bz2" % BOOST_VERSION,
        ],
    )
