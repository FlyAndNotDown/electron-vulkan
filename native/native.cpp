#include <node_api.h>
#include <iostream>
#include <vkt.h>

namespace demo {
    napi_value VkTestFunc(napi_env env, napi_callback_info args) {
        size_t argc = 1;
        napi_value argv[1];
        napi_get_cb_info(env, args, &argc, argv, nullptr, nullptr);

        void* value;
        napi_get_value_external(env, argv[0], &value);
        std::cout << value << std::endl;

        VkTest();
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