cmake_minimum_required(VERSION 3.20)
project(TodoList)

set(CMAKE_CXX_STANDARD 14)


# Qt setup
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(TodoList main.cpp mymodel.cpp mymodel.h ToDoListGUI.hpp LinkedPriorityList.hpp)
target_link_libraries(TodoList PUBLIC Qt5::Core Qt5::Widgets)
