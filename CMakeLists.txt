cmake_minimum_required(VERSION 3.28)
project(TankGame)


# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 查找SFML包
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 收集源文件
file(GLOB SOURCES "src/*.cpp")

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接SFML库
target_link_libraries(${PROJECT_NAME} 
    sfml-graphics 
    sfml-window 
    sfml-system
)