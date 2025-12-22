cmake_minimum_required(VERSION 3.30)

#-- Package cmaketk ------------------------------------------------------------

set(PACKAGE_NAME cmake_cpptk)
set(PACKAGE_VERSION 0.1.0) # dev

project(${PACKAGE_NAME} VERSION ${PACKAGE_VERSION} LANGUAGES CXX)
include(GNUInstallDirs)
set(PACKAGE_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PACKAGE_NAME}")

# target:
configure_file(include/cmake_cpptk/version.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/include/cmake_cpptk/version.hpp)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PACKAGE_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_sources(${PROJECT_NAME} PUBLIC FILE_SET HEADERS
    BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_BINARY_DIR}/include
    FILES
        include/cmake_cpptk/cmake.hpp
        include/cmake_cpptk/ctest.hpp
        include/cmake_cpptk/cmake_cpptk.hpp
        ${CMAKE_CURRENT_BINARY_DIR}/include/cmake_cpptk/version.hpp
)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

install(TARGETS ${PROJECT_NAME} EXPORT ${PACKAGE_NAME}-targets
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT ${PACKAGE_NAME}-targets DESTINATION ${PACKAGE_DIR} NAMESPACE "${PACKAGE_NAME}::")

# test
option(CMAKE_CPPTK_BUILD_TESTS "Build cmaketk tests." OFF)
if(CMAKE_CPPTK_BUILD_TESTS)
    include(CTest)
    if(BUILD_TESTING)
        add_subdirectory(test)
    endif()
endif()

#-- Install Package cmake_cpptk ----------------------------------------------------

include(CMakePackageConfigHelpers)

configure_package_config_file("cmake/config/package-config.cmake.in"
    "${PROJECT_BINARY_DIR}/${PACKAGE_NAME}-config.cmake"
    INSTALL_DESTINATION ${PACKAGE_DIR}
)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/${PACKAGE_NAME}-config-version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
configure_file(cmake/config/uninstall.cmake.in ${PROJECT_BINARY_DIR}/uninstall.cmake @ONLY)
install(FILES
    ${PROJECT_BINARY_DIR}/${PACKAGE_NAME}-config.cmake
    ${PROJECT_BINARY_DIR}/${PACKAGE_NAME}-config-version.cmake
    ${PROJECT_BINARY_DIR}/uninstall.cmake
    DESTINATION ${PACKAGE_DIR}
)
