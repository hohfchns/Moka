cmake_minimum_required(VERSION 3.10)
project(ProjectUsingMokaRenderer)

set(MOKA_LIBS MokaRenderer MokaWorld MokaECS MokaUtils)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include("${CMAKE_SOURCE_DIR}/cmake/opengl.cmake")

include_directories("${CMAKE_SOURCE_DIR}/vendor/moka/inc")
link_directories("${CMAKE_SOURCE_DIR}/vendor/moka/lib")

include_directories("${CMAKE_SOURCE_DIR}/vendor/gl/glad/inc")
link_directories("${CMAKE_SOURCE_DIR}/vendor/gl/glad/lib")

include_directories("${CMAKE_SOURCE_DIR}/inc")

file(
  GLOB SOURCE_FILES 
  "src/app.cpp"
)

add_executable(ProjectUsingMokaRenderer ${SOURCE_FILES})
target_link_libraries(ProjectUsingMokaRenderer ${MOKA_LIBS} ${GL_LIBS})
set_property(TARGET ProjectUsingMokaRenderer PROPERTY CXX_STANDARD 20)
set_property(TARGET ProjectUsingMokaRenderer PROPERTY CXX_STANDARD_REQUIRED 20)
