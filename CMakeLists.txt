cmake_minimum_required(VERSION 3.15)
project(illate)

set(CMAKE_CXX_STANDARD 17)

add_executable(illate main.cpp runtime/core.cpp runtime/ibool.cpp runtime/icontainer.cpp runtime/idouble.cpp runtime/iint.cpp runtime/inum.cpp runtime/istring.cpp runtime/item.cpp runtime/itemchain.cpp runtime/nill.cpp runtime/runtime.cpp)