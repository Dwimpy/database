cmake_minimum_required(VERSION 3.27)
project(database C)

set(CMAKE_C_STANDARD 11)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

include_directories(include)

add_executable(database
        include/ft_string.h
        src/ft_string.c
        main.c
        include/not_implemented.h)

#set_target_properties(database PROPERTIES
#    LINK_FLAGS "-static-libgcc -static-libstdc++ -static")