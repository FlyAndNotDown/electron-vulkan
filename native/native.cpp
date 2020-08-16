#include <node_api.h>
#include <iostream>
#include <vkt.h>

#ifndef _WIN32
#include <windows.h>
#endif

namespace demo {
    napi_value VkTestFunc(napi_env env, napi_callback_info args) {
#ifdef _WIN32
        FILE* stream = nullptr;
        freopen_s(&stream, "CONOUT$", "w", stdout);
#endif
        size_t argc = 1;
        napi_value argv[1];
        napi_get_cb_info(env, args, &argc, argv, nullptr, nullptr);

        int32_t value;
        napi_get_value_int32(env, argv[0], &value);
        std::cout << value << std::endl;

#ifdef _WIN32
        VkTest((HWND) value);
#else
        VkTest();
#endif

#ifdef _WIN32
        fclose(stream);
#endif
        return nullptr;
    }

    napi_value init(napi_env env, napi_value exports) {
        napi_status status;
        napi_value fn;

        status = napi_create_function(env, nullptr, 0, VkTestFunc, nullptr, &fn);
        if (status != napi_ok) return nullptr;

        status = napi_set_named_property(env, exports, "vkTest", fn);
        if (status != napi_ok) return nullptr;
        return exports;
    }

    NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
}