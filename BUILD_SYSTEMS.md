# Build Systems

## Table of Contents

- [Build system support](#build-system-support)
- [Installation](#installation)
  - [Install with CMake](#install-with-cmake)
  - [Install with Meson](#install-with-meson)
  - [Install with Autotools](#install-with-autotools)
- [Which build system should I use](#which-build-system-should-i-use)

## Build system support

yahelpers supports three build systems:

- **CMake**
- **Meson**
- **Autotools**

All build systems are fully maintained and tested in **CI**.

## Installation

yahelpers is a header‑only library. You can install it using any of the supported build systems.

### Install with CMake

```sh
cmake -B build
cmake --build build
sudo cmake --install build
```

Use in your project:

```cmake
find_package(yahelpers REQUIRED)
target_link_libraries(your_target PRIVATE yahelpers)
```

### Install with Meson

```sh
meson setup build
meson install -C build
```

Use in your project:

```meson
dependency('yahelpers')
```

### Install with Autotools

```sh
autoreconf --install
./configure
make
sudo make install
```

Use in your project:

```sh
pkg-config --cflags --libs yahelpers
```

### Which build system should I use?

yahelpers supports three build systems because different users have different needs:

|Buildsystem|Best suited for|Advantages|
|-----------|---------------|----------|
|CMake|Most users, modern C projects|Widely used, great IDE integration, provides CMake package config files|
|Meson|Users who want fast and clean builds|Very fast, simple syntax, minimal boilerplate|
|Autotools|Linux distributions, legacy environments|Standard in many distros, extremely portable and compatible|

**Recommendation**:  
For new projects → **CMake** or **Meson**.

For distributions → **Autotools**.
