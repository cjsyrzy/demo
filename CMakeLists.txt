# 指定CMAKE版本
cmake_minimum_required(VERSION 3.12.4)

# 设置工程名及版本号
project(demo VERSION 0.0.1)

# 指定C语言标准
# set(CMAKE_C_STANDARD 11)#C11
# set(CMAKE_CXX_STANDARD 17)#C17
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加预编译宏定义
add_compile_definitions(UNICODE _UNICODE)

# 添加编译文件

# 添加子cmkae及功能库
add_subdirectory(com)
list(APPEND EXTRA_LIBS com)

add_subdirectory(delay)
list(APPEND EXTRA_LIBS delay)

add_subdirectory(lin)
list(APPEND EXTRA_LIBS lin)

# add_subdirectory(lvgl)
# list(APPEND EXTRA_LIBS lvgl lvgl_demos)

# add_subdirectory(lv_drivers)
# list(APPEND EXTRA_LIBS lv_drivers)

# 添加可执行文件 exe
add_executable(demo main.c)

# 链接exe和库
target_link_libraries(demo PRIVATE ${EXTRA_LIBS})

target_include_directories(demo PRIVATE ${PROJECT_SOURCE_DIR})
