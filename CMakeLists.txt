cmake_minimum_required(VERSION 3.17)
project(electron_vulkan)

set(CMAKE_CXX_STANDARD 20)

# Node.js
include_directories(/usr/local/include/node)
include_directories(${CMAKE_JS_INC})

# GLFW
set(GLFW_HOME native/3rd/glfw)
include_directories(${GLFW_HOME}/include)
set(BUILD_SHARED_LIBS ON CACHE BOOL "build shared GLFW lib")
add_subdirectory(${GLFW_HOME})

# GLM
set(GLM_HOME native/3rd/glm)
include_directories(${GLM_HOME})

# STB Image
set(STB_HOME native/3rd/stb)
include_directories(${STB_HOME})

# Vulkan SDK
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

# Vulkan Demo
include_directories(native)
add_library(vulkan_demo STATIC native/vkt.cpp)
target_link_libraries(vulkan_demo glfw vulkan)

# Native Addon
file(GLOB SOURCE_FILES "native/native.cpp")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB} vulkan_demo)