# yahelpers

[![CI](https://github.com/asaeppel4231/yahelpers/actions/workflows/ci.yaml/badge.svg)](https://github.com/asaeppel4231/yahelpers/actions/workflows/ci.yaml)
[![Build and Deploy Docs](https://github.com/asaeppel4231/yahelpers/actions/workflows/docs.yaml/badge.svg)](https://github.com/asaeppel4231/yahelpers/actions/workflows/docs.yaml)
[![CodeQL Advanced](https://github.com/asaeppel4231/yahelpers/actions/workflows/codeql.yml/badge.svg?branch=master)](https://github.com/asaeppel4231/yahelpers/actions/workflows/codeql.yml)
[![Release](https://github.com/asaeppel4231/yahelpers/actions/workflows/release.yaml/badge.svg)](https://github.com/asaeppel4231/yahelpers/actions/workflows/release.yaml)

Some helper functionality for the ya ecosystem.

## Table of Contents

- [License](#license)
- [Features](#features)
- [ya‑ ecosystem](#ya--ecosystem)
- [Further Information](#further-information)

## License

This repository is released under the MPL-2.0 License, see [LICENSE.md](./LICENSE.md)

## Features

- Header-only C99 helper library  
- Debugging helpers (`assert.h`, `log.h`, `logconstants.h`)  
- Cross‑platform (Linux, macOS, Windows)  
- Supports **CMake**, **Meson**, **Autotools** and **pkg-config**  
- Designed for the **ya- ecosystem** (yastk, yaerrno, ... (more in the future))

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

## Further Information

- Build system details → [BUILD_SYSTEMS.md](./BUILD_SYSTEMS.md)
- Documentation & examples → [DOCUMENTATION_RELATED.md](./DOCUMENTATION_RELATED.md)
