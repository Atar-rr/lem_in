cmake_minimum_required(VERSION 2.8)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)
project(lem_in C)
set(CMAKE_C_STANDARD 90)
include_directories(./libftprintf ./libftprintf/includes ./libftprintf/ft_printf ./libftprintf/libft)
#link_directories(libftprintf)

add_executable(lemin main.c lem_in.h)
target_link_libraries(lemin libftprintf/libftprintf.a)