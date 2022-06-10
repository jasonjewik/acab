# A C++ Auto Battler

## Description
https://jasonjewik.notion.site/ACAB-Design-Doc-9141c8be7c64427dbb2c35cd77825042

## Usage
Everything should be done inside the Docker container.

Building and running the Docker image/container.
```shell
$ docker/build.sh
$ docker/start.sh
```

Building the source code.
```shell
$ mkdir build && cd build
$ cmake ..
$ make
```

Running tests.
```shell
$ cd build
$ ctest
```