cc_binary(
    name = "crow_client_bin",
    srcs = ["include/client.hpp","src/client.cpp","include/server_client.hpp","src/server_client.cpp"],
    linkopts = ["-lcurl"],
    deps = [
       "@boost//:algorithm",
       "@boost//:asio",
       "@boost//:system",
    ],
)

load("@io_bazel_rules_docker//container:container.bzl", "container_image","container_push")
load("//:var.bzl", "SERVER_PORT", "CLIENT_DELAY_MS","CLIENT_MAX_DURATION_SECONDS", "K8S_CLIENT_TO_SERVER_ENDPOINT")

container_image(
    name = "client_image",
    base = "@centos7_with_curl//image",
    files = [":crow_client_bin"],
    entrypoint = ["./crow_client_bin"],
    stamp = True,
    repository = "crow",
    labels = {
        "com.crow.client": "v1"
    },
    env = {
        "SERVER_PORT": SERVER_PORT,
        "CLIENT_DELAY_MS": CLIENT_DELAY_MS,
        "CLIENT_MAX_DURATION_SECONDS": CLIENT_MAX_DURATION_SECONDS,
    },
)

container_push(
   name = "client_push",
   image = ":client_image",
   format = "Docker",
   registry = "ghcr.io",
   repository = "kubecorn/test-crow/client",
   tag = "{BUILD_EMBED_LABEL}"
)

## K8S

container_image(
    name = "client_image_k8s",
    base = "@centos7_with_curl//image",
    files = [":crow_client_bin"],
    entrypoint = ["./crow_client_bin"],
    stamp = True,
    repository = "crow",
    labels = {
        "com.crow.client": "v1"
    },
    env = {
        "SERVER_PORT": SERVER_PORT,
        "CLIENT_DELAY_MS": CLIENT_DELAY_MS,
        "CLIENT_MAX_DURATION_SECONDS": CLIENT_MAX_DURATION_SECONDS,
        "SERVER_ENDPOINT": K8S_CLIENT_TO_SERVER_ENDPOINT
    },
)

container_push(
   name = "client_push_k8s",
   image = ":client_image_k8s",
   format = "Docker",
   registry = "ghcr.io",
   repository = "kubecorn/test-crow/client",
   tag = "{BUILD_EMBED_LABEL}"
)