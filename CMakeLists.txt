cmake_minimum_required(VERSION 3.0)

project(wsjcpp-email-validation C CXX)

find_package(Threads REQUIRED)

include(${CMAKE_CURRENT_SOURCE_DIR}/src.wsjcpp/CMakeLists.txt)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${wsjcpp-email-validation_SOURCE_DIR})

# Sources

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")

list (APPEND WSJCPP_SOURCES "src/wsjcpp_email_validation.cpp")
list (APPEND WSJCPP_SOURCES "src/main.cpp")

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable ("wsjcpp-email-validation" ${WSJCPP_SOURCES})

target_link_libraries("wsjcpp-email-validation" ${CMAKE_THREAD_LIBS_INIT} )

install(
    TARGETS
        "wsjcpp-email-validation"
    RUNTIME DESTINATION
        /usr/bin
)
