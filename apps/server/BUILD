cc_binary(
    name = "crow_server_bin",
    srcs = ["src/server.cpp"],
    deps = ["//third_party/crow:libcrow", "//third_party/getTimeOfDay:libtime", "//third_party/Config:libconfig"],
    linkopts = ["-lpthread"]
)


load("@io_bazel_rules_docker//cc:image.bzl", "cc_image")
load("@io_bazel_rules_docker//container:container.bzl", "container_image")
load("//:var.bzl", "SERVER_PORT", "SERVER_MESSAGE")

container_image(
    name = "server_image",
    files = [":crow_server_bin"],
    base= "@centos7_with_curl//image",
    entrypoint = "./crow_server_bin",
    ports = ["9080"],
    stamp = True,
    repository = "crow",
    labels = {
        "com.crow.server": "v1"
    },
    env = {
        "SERVER_PORT": SERVER_PORT,
        "SERVER_MESSAGE": SERVER_MESSAGE,
    },
    volumes=["/data"],
    workdir="/app",
)



#test image
load("@io_bazel_rules_docker//contrib:test.bzl", "container_test")
container_test(
    name = "test_image_server",
    configs = ["test_image_server.json"],
    image = ":server_image",
) 


load("@io_bazel_rules_docker//container:container.bzl", "container_push")

container_push(
   name = "server_push",
   image = ":server_image",
   format = "Docker",
   registry = "ghcr.io",
   repository = "kubecorn/test-crow/server",
   #tag = "v1",
   tag = "{BUILD_EMBED_LABEL}"
)
