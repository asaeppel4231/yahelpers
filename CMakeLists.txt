cmake_minimum_required(VERSION 3.10)

add_library(yahelpers INTERFACE)

target_include_directories(yahelpers INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/ya-ecosystem/bool>
)

install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/log.h
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/logconstants.h
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/assert.h
    DESTINATION include/ya-ecosystem/helpers
)

install(
    TARGETS yahelpers
    EXPORT yahelpersTargets
)