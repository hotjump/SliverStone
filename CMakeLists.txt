cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 查找gtest库
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 添加测试可执行文件
aux_source_directory(./src SRC_LIST)
add_executable(testcase ${SRC_LIST})
target_link_libraries(testcase ${GTEST_LIBRARIES} pthread)

# 使测试可被ctest识别
enable_testing()
add_test(NAME testcase COMMAND testcase)