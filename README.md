# pavucontrol-qt

This fork of pavucontrol-qt is focused on creating a simple and intuitive way for people to manage their sound devices and app sound output and interconnect them.

## Installation

Runtime dependencies:
* qtbase
* libpulse (PulseAudio client library)

Build dependencies:
* base-devel
* cmake
* ninja

#### 1st step: Clone the repo
```console
git clone --recurse-submodules https://github.com/edgararaj/pavucontrol-qt.git
```
or if you already cloned the repo and forgot --recurse-submodules,
```console
git submodule update --init --recursive
```

#### 2nd step: Build and install the project
```console
~/pavucontrol-qt$ mkdir build && cd build
~/pavucontrol-qt/build$ cmake -GNinja ..
~/pavucontrol-qt/build$ ninja install
```

#### 3rd step: Have fun! 🎉
To run just type:
```console
$ pavucontrol-qt
```

