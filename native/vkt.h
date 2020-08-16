#ifndef ELECTRON_VULKAN_VKT_H
#define ELECTRON_VULKAN_VKT_H

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
extern "C" void VkTest(HWND hWnd);
#else
extern "C" void VkTest();
#endif

#endif
