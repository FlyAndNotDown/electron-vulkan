const { app, BrowserWindow } = require('electron');
const NativeApi = require('./build/Release/electron_vulkan');

function createWindow () {
    // 创建浏览器窗口
    let win = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            nodeIntegration: true
        }
    })

    // 加载index.html文件
    win.loadFile('index.html');
    NativeApi.vkTest(win.getNativeWindowHandle());
}

app.whenReady().then(() => {
    createWindow();
});