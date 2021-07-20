workspace(name = "test_crow")

load("@//third_party:deps.bzl", "cc_deps")
cc_deps() 

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "io_bazel_rules_docker",
    sha256 = "480daa8737bf4370c1a05bfced903827e75046fea3123bd8c81389923d968f55",
    strip_prefix = "rules_docker-0.11.0",
    urls = ["https://github.com/bazelbuild/rules_docker/releases/download/v0.11.0/rules_docker-v0.11.0.tar.gz"],
)

# Gtest
http_archive(
    name = "gtest",
    url = "https://github.com/google/googletest/archive/release-1.7.0.zip",
    sha256 = "b58cb7547a28b2c718d1e38aee18a3659c9e3ff52440297e965f5edffe34b6d0",
    strip_prefix = "googletest-release-1.7.0",
    build_file="@//third_party:gtest.BUILD"
)


load("@io_bazel_rules_docker//toolchains/docker:toolchain.bzl",
    docker_toolchain_configure="toolchain_configure"
)

docker_toolchain_configure(
    name = "docker_config",
    docker_path = "/usr/bin/docker",
)


load(
    "@io_bazel_rules_docker//repositories:repositories.bzl",
    container_repositories = "repositories",
)
container_repositories()


load("@io_bazel_rules_docker//repositories:deps.bzl", container_deps = "deps")
container_deps()


load("@io_bazel_rules_docker//repositories:pip_repositories.bzl", "pip_deps")
pip_deps()


load(
    "@io_bazel_rules_docker//cc:image.bzl",
    _cc_image_repos = "repositories",
)
_cc_image_repos()

# docker image used by client
load("@io_bazel_rules_docker//container:container.bzl", "container_pull")

container_pull(
    name = "cc_curl",
    registry = "docker.pkg.github.com",
    repository = "kubecorn/test-crow/cc_curl",
    tag = "v1.3"
)


# docker image used by client
load("@io_bazel_rules_docker//container:container.bzl", "container_pull")

container_pull(
    name = "centos7_with_curl",
    registry = "ghcr.io",
    repository = "kubecorn/test-crow/centos7_curl",
    tag = "1.0",
)

#test image
http_archive(
    name = "bazel_skylib",
    urls = [
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.0.3/bazel-skylib-1.0.3.tar.gz",
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.0.3/bazel-skylib-1.0.3.tar.gz",
    ],
    sha256 = "1c531376ac7e5a180e0237938a2536de0c54d93f5c278634818e0efc952dd56c",
)
load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
bazel_skylib_workspace()


load(
    "@io_bazel_rules_docker//contrib:test.bzl",
    "container_test",
)