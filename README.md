# ChatGPT Linux Launcher

This repo is tiny ChatGPT Launcher that you can use with a keyboard shortcut, like on Windows.

## Requirements

To install the required packages, run the following commands :

```bash
sudo apt install libwebkit2gtk-4.0-dev libgtk-3-dev
```

## Installation

Clone the repository and build the program with the following commands:

```bash*
git clone "https://github.com/killianmarty/ChatGPTLinuxLauncher && cd ChatGPTLinuxLauncher
chmod +x build.sh && ./build.sh
```

Once installed, you can add a keyboard shortcut on your Desktop Environment that launch to following command :

```bash
bash -c "cd /path/to/the/repository/directory && ./ChatGPT"
```

## Author

This project was created by Killian Marty.