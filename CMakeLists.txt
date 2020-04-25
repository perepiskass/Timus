cmake_minimum_required(VERSION 3.2)

project(timus VERSION 1.1.1)

add_executable(timus1196 timus1196.cpp)
add_executable(timus1496 timus1496.cpp)
add_executable(timus1545 timus1545.cpp)
add_executable(timus1837 timus1837.cpp)

set_target_properties(timus1837 PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)
