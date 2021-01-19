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
First clone this repository
```bash
$ git clone https://github.com/h-valdes/bgmaker
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

# Samples
![](screenshots/background.png)