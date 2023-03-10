# 添加cmake版本
cmake_minimum_required(VERSION 3.12.4)

# 添加工程名及版本号
project(display VERSION 0.1.0)

# 定义编程语言版本
# set(CMAKE_C_STANDARD 11)#C11
# set(CMAKE_CXX_STANDARD 17)#C17
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加预编译宏定义
add_compile_definitions(UNICODE _UNICODE)

# include(CTest)
# enable_testing()

# add_compile_definitions(WINVER=0x0602 _WIN32_WINNT=0x0602)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

# add_subdirectory(lv_drivers)
# list(APPEND EXTRA_LIBS lv_drivers)

# add_subdirectory(lv_demos)
# list(APPEND EXTRA_LIBS lv_demos)

add_subdirectory(lvgl)
add_subdirectory(lv_drivers)

add_executable(display main.c)
# link library
target_link_libraries(display PRIVATE lvgl::lvgl lvgl::demos lvgl::drivers)

target_include_directories(display
                           PRIVATE ${PROJECT_SOURCE_DIR})