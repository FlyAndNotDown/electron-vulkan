cmake_minimum_required(VERSION 3.17)
project(electron_vulkan)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    message(FATAL_ERROR "[err] this project is not support Windows yet")
elseif(APPLE)
    message("[info] os is MacOS")
elseif(UNIX)
    message(FATAL_ERROR "[err] this project is not support Unix yet")
endif()

# Node.js
## this line is just for cxx hints, you can just remove it
include_directories(/usr/local/include/node)
include_directories(${CMAKE_JS_INC})
message("[info] Node.js configured")

# GLFW
set(GLFW_HOME native/3rd/glfw)
include_directories(${GLFW_HOME}/include)
set(BUILD_SHARED_LIBS ON CACHE BOOL "build shared GLFW lib")
add_subdirectory(${GLFW_HOME})
message("[info] GLFW configured")

# GLM
set(GLM_HOME native/3rd/glm)
include_directories(${GLM_HOME})
message("[info] GLM configured")

# STB Image
set(STB_HOME native/3rd/stb)
include_directories(${STB_HOME})
message("[info] STB_Image configured")

# Vulkan SDK
find_package(Vulkan REQUIRED)
include_directories(${Vulkan_INCLUDE_DIRS})
message("[info] VulkanSDK configured")

# Vulkan Demo
include_directories(native)
add_library(vulkan_demo STATIC native/vkt.cpp)
target_link_libraries(vulkan_demo glfw ${Vulkan_LIBRARY})
message("[info] VulkanDemo configured")

# Native Addon
file(GLOB SOURCE_FILES "native/native.cpp")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB} vulkan_demo)
message("[info] native addon configured")