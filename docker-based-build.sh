#!/bin/sh
# builds using the davidsiaw/ndk-env image

docker run --rm -e JAVA_HOME=/usr/lib/jvm/java-7-openjdk-amd64 -v $PWD:/src --platform=linux/amd64 davidsiaw/ndk-env:original-api-level-10
