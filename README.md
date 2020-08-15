# Electron-Vulkan

一个在 `Electron` 进程中使用 `Vulkan` 进行 `3D` 绘图的简单例子。

# 环境要求

* `MacOS`：其他系统暂不支持
* `CMake`
* `Node.js`
* `VulkanSDK`

# 环境配置

先安装 `Vulkan SDK`、`Node.js`、`CMake`，完成安装后配置一条 `Electron` 的代理，这里推荐使用华为镜像（淘宝的试了好像不行）：

```shell
npm config set electron_mirror https://mirrors.huaweicloud.com/electron/
```

接下来安装依赖：

```shell
npm install
```

# 构建 C++ Addon

```shell
npm run compile
```

# 运行

```shell
npm run start
```
