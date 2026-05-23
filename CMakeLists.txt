cmake_minimum_required(VERSION 3.15)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
project(audio-sandbox CXX)

find_package(fmt CONFIG REQUIRED)
find_package(range-v3 CONFIG REQUIRED)
find_package(cxxopts CONFIG REQUIRED)
find_package(OpenAL CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(audio-sandbox main.cpp)

target_link_libraries(audio-sandbox 
  PRIVATE
    fmt::fmt
    range-v3::range-v3
    cxxopts::cxxopts
    OpenAL::OpenAL)