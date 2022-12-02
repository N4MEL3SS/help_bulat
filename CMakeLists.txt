cmake_minimum_required(VERSION 3.21)
project(help_bulat)

set(CMAKE_CXX_STANDARD 14)

add_executable(deque Deque/Deque.hpp Deque/main.cpp Deque/TestDeque.cpp Deque/TestDeque.hpp)
add_executable(list List/list.hpp List/main.cpp List/TestList.cpp List/TestList.hpp)
add_executable(tree Tree/main3.cpp)
add_executable(list_class list_class/list_class.cpp list_class/list_class.hpp list_class/main.cpp)
add_executable(deque_bulat Deque/deck2.cpp)
add_executable(tree_new Tree/mainnew.cpp)

target_compile_options(tree_new PRIVATE -fsanitize=address)
target_link_options(tree_new PRIVATE -fsanitize=address)
