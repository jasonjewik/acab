FROM ubuntu

# Install packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libgtest-dev \
    python3 \
    python3-dev \
    python3-pip \
    python-is-python3

RUN pip3 install "pybind11[global]"

# We are going to mount the current working directory into my-project
ENV HOME=/home/my-project
RUN mkdir -p $HOME

# Set Python path so we can import the shared libraries
ENV PYTHONPATH=$PYTHONPATH:$HOME/build/shared

# When running the container, we'll start in my-project
WORKDIR $HOME
CMD ["/bin/bash"]