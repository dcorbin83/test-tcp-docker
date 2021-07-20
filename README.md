# test-crow
``` bash
.
├── apps
│   ├── client
│   │   ├── BUILD
│   │   └── src
│   │       └── client.cpp
│   ├── server
│   │   ├── BUILD
│   │   └── src
│   │       └── server.cpp
│   └── test
│       ├── BUILD
│       └── src
│           └── TestServer.cpp
├── docker
│   └── Dockerfile.base
├── LICENSE
├── README.md
├── third_party
│   ├── boost.bzl
│   ├── BUILD
│   ├── BUILD.boost
│   ├── Config
│   │   ├── BUILD
│   │   ├── include
│   │   │   └── Config.h
│   │   └── src
│   │       └── Config.cpp
│   ├── crow
│   │   ├── BUILD
│   │   └── crow_all.h
│   ├── deps.bzl
│   ├── getTimeOfDay
│   │   ├── BUILD
│   │   ├── include
│   │   │   └── TimeStamp.h
│   │   └── src
│   │       └── TimeStamp.cpp
│   └── gtest.BUILD
└── WORKSPACE

```
# setup
you need to install curl to build the client app
``` bash
sudo yum install libcurl-devel
``` 

# build
``` bash
git clone https://github.com/kubeCorn/test-crow.git
cd test-crow
bazel build //apps/server:crow_server_bin
bazel build //apps/client:crow_client_bin

```
# create image
``` bash
bazel run //apps/server:server_image
bazel run //apps/client:client_image


```
# push image
``` bash
bazel run //apps/server:server_push --embed_label="your_new_image_version"
bazel run //apps/client:client_push  --embed_label="your_new_image_version"

```
## [optional] if you want to test from ssh tunnel make sure ssh is active on the host
``` bash
in VBox : Conf/network/NAT -> advanced port fowarding : ssh | TCP | 127.0.0.1  |  2522 | <IP_VM> | 22
systemctl ssh status // active(running) if not installed ( try sudo yum –y install openssh-server openssh-clients ) 
also verify response from ping 8.8.8.8 -> ok you are connected to the wwweb
```

# test on port 8080 with "hello world" message each "200 ms"
``` bash
./crow_server 8080 "hello world" 200 //terminal 1
./crow_client 8080 // terminal 2  
```
``` console
response in Terminal1 : {"Message":"hello world","ID":57,"Date":"Thu Oct  1 11:09:26 2020\n"}
```

# Test with image
``` bash 
for now the port is hard coded in the image
docker run -d -p 9080:9080 crow/apps/server:server_image
docker run --net=host --rm  crow/apps/client:client_image
```
# Unit Test 
``` bash
bazel build //apps/test:test
bazel-bin/apps/test/test
```
``` console
response  :==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from TestServer
[ RUN      ] TestServer.when_set_Port_Message_Should_Works
    
    // ... // 

[       OK ] TestServer.when_Unset_all_Should_Default (0 ms)
[----------] 4 tests from TestServer (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.

```
# Docker-compose

Setup Docker-Compose : https://docs.docker.com/compose/install/

``` bash
cd ./docker_compose/
docker-compose --env-file ../var.bzl up

docker ps # Get Containers ID
docker exec -it CONTAINER_ID bash # Open bash in container
```
