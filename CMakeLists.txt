project(TeoLang)
cmake_minimum_required(VERSION 3.25)
execute_process(COMMAND cat ${CMAKE_CURRENT_LIST_DIR}/banner)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

set(CMAKE_CXX_FLAGS "-Wall")

execute_process(
    COMMAND git describe --abbrev=7 --dirty --always --tags
    OUTPUT_VARIABLE GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )
add_compile_definitions(VERSION="${GIT_HASH}")
message(STATUS "Git version: ${GIT_HASH}")

set(PLATFORM ${CMAKE_SYSTEM_NAME})
message(STATUS "Platform: ${PLATFORM}")

set(ARCH ${CMAKE_SYSTEM_PROCESSOR})
message(STATUS "Arch: ${ARCH}")

include_directories(${CMAKE_CURRENT_LIST_DIR}/cparse)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_executable(main
    main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/interpret.cpp
    ${CMAKE_CURRENT_LIST_DIR}/parse_file.cpp
    ${CMAKE_CURRENT_LIST_DIR}/codelistHandler.cpp
    ${CMAKE_CURRENT_LIST_DIR}/guihelper.cpp
    ${CMAKE_CURRENT_LIST_DIR}/cparse/core-shunting-yard.o
    ${CMAKE_CURRENT_LIST_DIR}/cparse/builtin-features.o
    )
target_link_libraries(main ${GTK3_LIBRARIES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GTK3_CFLAGS_OTHER}")
