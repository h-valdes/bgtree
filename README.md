# bgmaker (Background Maker)

Create background images using C++, ImageMagick and L-Systems.
This is a WIP.

# Getting Started

## Requirements
Install the library ImageMagick. 
In Ubuntu 20.04
```bash
$ sudo apt install libmagick++-dev
```

## Build
Clone this repository and all his submodules
```bash
$ git clone --recursive https://github.com/h-valdes/bgmaker
```

```bash
$ cd bgmaker
$ mkdir build
$ cd Build
$ cmake ..
$ make
```

## Use
Inside of the build directory:
```bash
$ ./bgmaker draw
```

And to preview the image with ImageMagick
```bash
$ ./bgmaker draw --preview
```

To override the default values use the config file 
```bash
$ ./bgmaker draw --preview --config "../config.toml"
```

# Samples
![](screenshots/background.png)