cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(raytracer CXX C)

set(CMAKE_CXX_STANDARD 17)

# ---[ Eigen
set(EIGEN_MPL2_ONLY 1)
find_package(Eigen3 QUIET)
if (EIGEN3_FOUND)
    include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})
else()
    include_directories(SYSTEM ${PROJECT_SOURCE_DIR}/third_party/eigen)
endif()

# ---[ Main build
add_subdirectory(raytracer)
