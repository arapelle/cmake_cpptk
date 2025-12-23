cmake_minimum_required(VERSION 3.30)

project(PackageTest CXX)

find_package(cmake_cpptk CONFIG REQUIRED)

add_executable(test_package test_package.cpp)
target_compile_features(test_package PRIVATE cxx_std_20)
target_link_libraries(test_package PRIVATE cmake_cpptk::cmake_cpptk)
