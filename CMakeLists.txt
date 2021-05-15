cmake_minimum_required(VERSION 3.0)
project(stadion)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors -g)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(main main.cpp menu.cpp menu_main_func.cpp stadium.cpp seat.cpp log.cpp) 
