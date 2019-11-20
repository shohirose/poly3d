cmake_minimum_required(VERSION 3.13)
project(poly3d C CXX)

add_executable(poly3d
    # Source files
    poly3d.c
    elastic.c
    getoptPoly3D.c
    getwords.c
    infcoeff.c
    matrix.c
    nr.c
    nrutil.c
    safetan.c
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
    # c_std_11
    # cxx_std_11
  )
target_compile_options(poly3d
  PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -ansi
  )
target_include_directories(poly3d
  PRIVATE
    ${PROJECT_SOURCE_DIR}
  )