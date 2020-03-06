cmake_minimum_required(VERSION 3.13)
project(poly3d CXX)

add_executable(poly3d)
target_compile_features(poly3d
  PRIVATE
    cxx_std_14
  )
target_compile_options(poly3d
  PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
  )
target_include_directories(poly3d
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include/poly3d
  )
target_compile_definitions(poly3d
  PUBLIC
    $<$<PLATFORM_ID:Windows>:_USE_MATH_DEFINES>
    $<$<CONFIG:Debug>:DEBUG>
  )

add_subdirectory(include)
add_subdirectory(src)