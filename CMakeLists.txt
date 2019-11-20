cmake_minimum_required(VERSION 3.13)
project(poly3d CXX)

add_executable(poly3d
    # Source files
    poly3d.cpp
    elastic.cpp
    getoptPoly3D.cpp
    getwords.cpp
    infcoeff.cpp
    matrix.cpp
    nr.cpp
    nrutil.cpp
    safetan.cpp
    # Header files
    elastic.h
    getoptPoly3D.h
    getwords.h
    infcoeff.h
    matrix.h
    nr.h
    nrutil.h
    pi.h
    safetan.h
  )
target_compile_features(poly3d
  PRIVATE
    cxx_std_14
  )
target_compile_options(poly3d
  PRIVATE
    -Wall
    -Wextra
    -Wpedantic
  )
target_include_directories(poly3d
  PRIVATE
    ${PROJECT_SOURCE_DIR}
  )