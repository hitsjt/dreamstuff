project(QtPluginTest)

cmake_minimum_required(VERSION 2.6)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})


add_subdirectory(TestPlugin)


include_directories(TestPlugin)
link_directories(TestPlugin)

qt4_wrap_cpp(TestClass_MOC TestClass.h)

add_executable(test main.cpp ${TestClass_MOC})
target_link_libraries(test ${QT_LIBRARIES})