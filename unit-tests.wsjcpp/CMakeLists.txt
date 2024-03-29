# Automaticly generated by wsjcpp@v0.2.2
cmake_minimum_required(VERSION 3.0)

project(unit-tests C CXX)
add_definitions(-DWSJCPP_APP_VERSION="ut-v0.1.2")
add_definitions(-DWSJCPP_APP_NAME="unit-tests-wsjcpp-email-validators")

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX TRUE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${unit-tests_SOURCE_DIR})

set (WSJCPP_LIBRARIES "")
set (WSJCPP_INCLUDE_DIRS "")
set (WSJCPP_SOURCES "")

find_package(Threads REQUIRED)
list (APPEND WSJCPP_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})

# wsjcpp-core:v0.2.3
list (APPEND WSJCPP_INCLUDE_DIRS "../src.wsjcpp/wsjcpp_core/")
list (APPEND WSJCPP_SOURCES "${CMAKE_SOURCE_DIR}/../src.wsjcpp/wsjcpp_core/wsjcpp_core.cpp")
list (APPEND WSJCPP_SOURCES "${CMAKE_SOURCE_DIR}/../src.wsjcpp/wsjcpp_core/wsjcpp_core.h")
list (APPEND WSJCPP_SOURCES "${CMAKE_SOURCE_DIR}/../src.wsjcpp/wsjcpp_core/wsjcpp_unit_tests.cpp")
list (APPEND WSJCPP_SOURCES "${CMAKE_SOURCE_DIR}/../src.wsjcpp/wsjcpp_core/wsjcpp_unit_tests.h")
list (APPEND WSJCPP_SOURCES "${CMAKE_SOURCE_DIR}/../src.wsjcpp/wsjcpp_core/wsjcpp_unit_tests_main.cpp")

# wsjcpp-email-validators:v0.1.2
list (APPEND WSJCPP_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/../src")
list (APPEND WSJCPP_SOURCES "${CMAKE_SOURCE_DIR}/../src/wsjcpp_email_validation.h")
list (APPEND WSJCPP_SOURCES "${CMAKE_SOURCE_DIR}/../src/wsjcpp_email_validation.cpp")

# unit-tests
list (APPEND WSJCPP_INCLUDE_DIRS "src")
list (APPEND WSJCPP_SOURCES "${CMAKE_SOURCE_DIR}/../unit-tests.wsjcpp/src/unit_test_validator_email.cpp")

# required-libraries
list (APPEND WSJCPP_LIBRARIES "-lpthread")

include(${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.user-custom.txt)


include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable ("unit-tests" ${WSJCPP_SOURCES})

target_link_libraries("unit-tests" -lpthread ${WSJCPP_LIBRARIES} )

