const { app, BrowserWindow } = require('electron');
const NativeApi = require('./build/Release/electron_vulkan');

function createWindow () {
    let win = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            nodeIntegration: true
        }
    })

    win.loadFile('index.html');
    NativeApi.vkTest(win.getNativeWindowHandle());
}

app.whenReady().then(() => {
    createWindow();
});