cmake_minimum_required(VERSION 3.16)
project(yahelpers VERSION 0.1 LANGUAGES C)

include(GNUInstallDirs)

# Header-only library
add_library(yahelpers INTERFACE)
target_include_directories(yahelpers INTERFACE
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/ya-ecosystem/helpers>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

# Install headers
install(FILES
    assert.h
    log.h
    logconstants.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ya-ecosystem/helpers
)

# Install the CMake package config
install(TARGETS yahelpers
    EXPORT yahelpersTargets
)

install(EXPORT yahelpersTargets
    FILE yahelpersTargets.cmake
    NAMESPACE ya::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/yahelpers
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/yahelpersConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/yahelpersConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/yahelpers
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/yahelpersConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/yahelpersConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/yahelpersConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/yahelpers
)

# pkg-config file
configure_file(
    yahelpers.pc.in
    yahelpers.pc
    @ONLY
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/yahelpers.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)
