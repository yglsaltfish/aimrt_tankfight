#!/bin/bash

# exit on error and print each command
set -e

# 创建并进入构建目录
cmake -B build $@

# 直接构建项目，移除install相关的命令
cmake --build build --config Release --parallel $(nproc)