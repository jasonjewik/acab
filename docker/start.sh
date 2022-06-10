#!/bin/bash
docker run --rm -it \
    --mount type=bind,src="$(pwd)",dst=/home/my-project \
    --entrypoint bash \
    acab:latest