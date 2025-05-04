cmake_minimum_required(VERSION 3.26)
project(Snake)

#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_COMPILER clang++-18)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES ON) #required for ninja building
set(CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS "/usr/bin/cland-scan-deps-18")
set(FLAGS -Wall -Wextra -Wpedantic -Werror)
set(SFML_LIB    sfml-graphics
                sfml-window
                sfml-system)

set(SRC_MOD     Headers/Food.cppm
                Headers/Snake.cppm
                Headers/Controller.cppm
                Headers/RenderingUtils.cppm)

set(SRC Source/Food.cpp
        Source/Snake.cpp
        Source/Controller.cpp
        Source/RenderingUtils.cpp)


set(GMOCK_LIBRARIES     /usr/lib/libgmock.a     /usr/lib/libgmock_main.a)
find_package(GTest      REQUIRED)

add_library(${PROJECT_NAME}-lib STATIC)
target_compile_features(${PROJECT_NAME}-lib  PUBLIC cxx_std_20)
target_sources(${PROJECT_NAME}-lib
        PUBLIC
                FILE_SET modules TYPE CXX_MODULES FILES ${SRC_MOD}
        PRIVATE
                ${SRC}
) 
target_link_libraries(${PROJECT_NAME}-lib PRIVATE ${SFML_LIB})

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-gt testRunner.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${SFML_LIB} ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-gt PRIVATE ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} ${SFML_LIB} ${PROJECT_NAME}-lib)

target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-gt PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

set_target_properties(${PROJECT_NAME}-lib PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
set_target_properties(${PROJECT_NAME}-gt PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
