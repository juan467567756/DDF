# Build stage
FROM ubuntu:22.04 AS build
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git
WORKDIR /app
COPY . /app
RUN git submodule update --init --recursive
RUN mkdir build && cd build && \
    cmake .. && \
    make && \
    make install

# Runtime stage
FROM ubuntu:22.04
WORKDIR /app
COPY --from=build /usr/local/bin/ddf /usr/local/bin/ddf
ENTRYPOINT ["ddf"]

