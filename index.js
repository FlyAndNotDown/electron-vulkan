const { app, BrowserWindow } = require('electron');
const OS = require('os');
const NativeApi = require('./build/Release/electron_vulkan');

function readNativeHandle(buf) {
    return OS.type() === 'Windows_NT' ? buf.readInt32LE(0) : buf.readInt32BE(0);
}

function createWindow () {
    let win = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            nodeIntegration: true
        }
    })
    win.loadFile('index.html').then(() => {
        console.log('index.html loaded');
    });

    // using vulkan in electron
    NativeApi.vkTest(readNativeHandle(win.getNativeWindowHandle()));
}

app.whenReady().then(() => {
    createWindow();
});