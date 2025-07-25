cmake_minimum_required(VERSION 3.28)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/binary)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/binary)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/binary/tests-out)

project(
    memory-pool
    VERSION 1.0.0
    LANGUAGES C
)

enable_testing()

#getting source files
file(GLOB LIB_SRC "${CMAKE_SOURCE_DIR}/*.c")

add_library(
    mpool STATIC
    ${LIB_SRC}
)
target_include_directories(mpool PRIVATE "${CMAKE_SOURCE_DIR}/include")

add_library(
    dmpool SHARED
    ${LIB_SRC}
)
target_include_directories(dmpool PRIVATE "${CMAKE_SOURCE_DIR}/include")


#configure tests
add_executable(allocate_pool_test "${CMAKE_SOURCE_DIR}/tests/allocate_pool_test.c")
target_link_libraries(allocate_pool_test PRIVATE mpool)
add_test(NAME apool COMMAND allocate_pool_test)

add_executable(init_pool_test "${CMAKE_SOURCE_DIR}/tests/init_pool_test.c")
target_link_libraries(init_pool_test PRIVATE mpool)
add_test(NAME ipool COMMAND init_pool_test)

add_executable(release_pool_test "${CMAKE_SOURCE_DIR}/tests/release_pool_test.c")
target_link_libraries(release_pool_test PRIVATE mpool)
add_test(NAME rpool COMMAND release_pool_test)