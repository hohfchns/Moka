cmake_minimum_required(VERSION 3.10)
project(Moka)

if(NOT SKIP_MOKA_LOGGER)
add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/MokaLogger"
)
endif()

if(NOT SKIP_MOKA_UTILS)
add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/MokaUtils"
)
endif()

if(NOT SKIP_MOKA_ECS)
add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/MokaECS"
)
endif()

if(NOT SKIP_MOKA_WORLD)
add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/MokaWorld"
)
endif()

if(NOT SKIP_MOKA_RENDERER)
add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/MokaRenderer"
)
endif()

