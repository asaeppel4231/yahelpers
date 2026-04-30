# yahelpers

[![CI](https://github.com/asaeppel4231/yahelpers/actions/workflows/ci.yaml/badge.svg)](https://github.com/asaeppel4231/yahelpers/actions/workflows/ci.yaml)
[![Build and Deploy Docs](https://github.com/asaeppel4231/yahelpers/actions/workflows/docs.yaml/badge.svg)](https://github.com/asaeppel4231/yahelpers/actions/workflows/docs.yaml)
[![CodeQL Advanced](https://github.com/asaeppel4231/yahelpers/actions/workflows/codeql.yml/badge.svg?branch=master)](https://github.com/asaeppel4231/yahelpers/actions/workflows/codeql.yml)
[![Release](https://github.com/asaeppel4231/yahelpers/actions/workflows/release.yaml/badge.svg)](https://github.com/asaeppel4231/yahelpers/actions/workflows/release.yaml)

Some helper functionality (debug helpers) for the ya ecosystem.

## Table of Contents

- [License](#license)
- [Documentation](#documentation)
- [Features](#features)
- [Minimal Example](#minimal-example)
- [Build system support](#build-system-support)
- [Installation](#installation)
  - [Install with CMake](#install-with-cmake)
  - [Install with Meson](#install-with-meson)
  - [Install with Autotools](#install-with-autotools)
- [Which build system should I use](#which-build-system-should-i-use)
- [ya‑ ecosystem](#ya--ecosystem)

## License

This repository is released under the MPL-2.0 License, see [LICENSE.md](./LICENSE.md)

## Documentation

The documentation is generated using **Doxygen**.

- 📘 **HTML Documentation:**
  <https://asaeppel4231.github.io/yahelpers/>

<!-- 📄 **PDF Documentation:**
  <https://asaeppel4231.github.io/yahelpers/pdf/yahelpers.pdf>
-->

### Building the documentation locally

If you prefer to generate the documentation locally instead of using the online version, run:

```sh
# Make sure the following packages are installed:
# - doxygen
# - graphviz
# - texlive-latex-base
# - texlive-latex-recommended
# - texlive-latex-extra
# - texlive-fonts-recommended
doxygen Doxyfile
#cd doxygen-doc/latex PDF CURRENTLY NOT SUPPORTED DUE TO BUILD ERRORS
#make
```

---

## Features

- Header-only C99 helper library  
- Debugging helpers (`assert.h`, `log.h`, `logconstants.h`)  
- Cross‑platform (Linux, macOS, Windows)  
- Supports **CMake**, **Meson**, **Autotools** and **pkg-config**  
- Designed for the **ya- ecosystem** (yastk, yaerrno, ... (more in the future))

---

## Minimal Example

```c
#include <ya-ecosystem/helpers/log.h>
#include <ya-ecosystem/helpers/assert.h>

int main(void) {
    LOG_DEBUG("Program started");

    int x = 5;
    ASSERT(x == 5, ASSERT_DEFAULT);   // will abort with a helpful message if false

    LOG_DEBUG("x = %d", x);

    return 0;
}
```

### Build system support

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

### *ya- Ecosystem*

yahelpers is part of the emerging ya- ecosystem, a collection of small, modular C libraries:

- yahelpers – Debugging helpers
- yastk – Stack library
- yaerrno – Error system
- yabool – Boolean utilities

The goals of all *ya- libraries* are:

- header‑only or minimalistic
- C99‑compatible
- cross‑platform
- usable with multiple build systems
