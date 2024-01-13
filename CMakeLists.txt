cmake_minimum_required(VERSION 3.10)
project(Moka)

add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/MokaLogger"
)

add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/MokaUtils"
)

add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/MokaECS"
)

add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/MokaWorld"
)

add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/MokaRenderer"
)

