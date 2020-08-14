# Electron-Vulkan

一个在 `Electron` 进程中使用 `Vulkan` 进行 `3D` 绘图的简单例子。

# 环境要求

* `MacOS`：其他系统暂不支持
* `Node.js`
* `VulkanSDK`

# 环境配置

首先安装 `VulkanSDK`：[VulkanSDK - Lunarg](https://vulkan.lunarg.com/sdk/home)，按照官方教程一步步安装即可 [Getting Start - Vulkan](https://vulkan.lunarg.com/doc/sdk/1.2.148.1/mac/getting_started.html)，接下来安装 `Node.js`：[Node.js](http://nodejs.cn/)

完成安装后配置一条 `Electron` 的代理，这里推荐使用华为镜像（淘宝的试了好像不行）：

```shell
npm config set electron_mirror https://mirrors.huaweicloud.com/electron/
```

# 构建 C++ Addon

```shell
npm run compile
```

# 运行

```shell
npm run start
```
