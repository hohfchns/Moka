cmake_minimum_required(VERSION 3.10)
project(ProjectUsingMoka)

set(MOKA_LIBS MokaECS MokaUtils MokaLogger)

include_directories("${CMAKE_SOURCE_DIR}/vendor/moka/inc")
link_directories("${CMAKE_SOURCE_DIR}/vendor/moka/lib")

include_directories("${CMAKE_SOURCE_DIR}/inc")

file(
  GLOB SOURCE_FILES 
  "src/app.cpp"
)

add_executable(ProjectUsingMoka ${SOURCE_FILES})
target_link_libraries(ProjectUsingMoka ${MOKA_LIBS})
set_property(TARGET ProjectUsingMoka PROPERTY CXX_STANDARD 20)
set_property(TARGET ProjectUsingMoka PROPERTY CXX_STANDARD_REQUIRED 20)
