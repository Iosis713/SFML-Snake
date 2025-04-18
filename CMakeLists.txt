cmake_minimum_required(VERSION 3.26)
project(Snake)

set(CMAKE_CXX_COMPILER clang++-18)
set(CMAKE_CXX_EXTENSIONS OFF)
set(FLAGS -Wall -Wextra -Wpedantic -Werror)
set(SFML_LIB    sfml-graphics
                sfml-window
                sfml-system)

set(SRC Food.cpp
        Snake.cpp)

set(GMOCK_LIBRARIES     /usr/lib/libgmock.a     /usr/lib/libgmock_main.a)
find_package(GTest      REQUIRED)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})
add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-gt testRunner.cpp)     

target_link_libraries(${PROJECT_NAME} PRIVATE ${SFML_LIB} ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-gt PRIVATE ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} ${SFML_LIB} ${PROJECT_NAME}-lib)

target_compile_options(${PROJECT_NAME}-gt PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})

set_target_properties(${PROJECT_NAME}-gt PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
set_target_properties(${PROJECT_NAME}-lib PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
