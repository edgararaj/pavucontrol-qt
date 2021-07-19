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
```
git clone --recurse-submodules https://github.com/edgararaj/pavucontrol-qt.git
```
or if you already cloned the repo and forgot --recurse-submodules,
```
git submodule update --init --recursive
```

#### 2nd step: Build and install the project
```console
foo@bar:~/pavucontrol-qt$ mkdir build && cd build
foo@bar:~/pavucontrol-qt/build$ cmake -GNinja ..
foo@bar:~/pavucontrol-qt/build$ ninja
```

#### 3rd step: Have fun! 🎉
To run just type:
```console
foo@bar:~/pavucontrol-qt/build$ src/pavucontrol-qt
```

