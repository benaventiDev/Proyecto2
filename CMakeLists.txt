cmake_minimum_required(VERSION 3.15)
project(KeyLogger)

set(CMAKE_CXX_STANDARD 14)

add_executable(KeyLogger main.cpp KeyConstants.h Helper.h Base64.h IO.h KeybHook.h)