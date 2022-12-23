project(TeoLang)
cmake_minimum_required(VERSION 3.25)
execute_process(COMMAND cat ${CMAKE_CURRENT_LIST_DIR}/banner)

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
add_executable(main
    main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/interpret.cpp
    ${CMAKE_CURRENT_LIST_DIR}/parse_file.cpp
    ${CMAKE_CURRENT_LIST_DIR}/cparse/core-shunting-yard.o
    ${CMAKE_CURRENT_LIST_DIR}/cparse/builtin-features.o
    )
