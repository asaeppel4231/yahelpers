# Contributing to yahelpers

Thank you for your interest in contributing to **yahelpers**.
This project is part of the ya- ecosystem, a collection of small, modular, C99‑compatible libraries.

## 📦 Project Overview

yahelpers is a header‑only C99 library providing logging and debugging utilities.  
It supports multiple build systems: **CMake**, **Meson**, and **Autotools**.

## 📝 How to Contribute

### 1. Reporting Issues

When opening an issue, please include:

- a clear description of the problem
- expected vs. actual behavior
- a minimal reproducible example
- your build system (CMake, Meson, Autotools)
- compiler and version

### 2. Submitting Pull Requests

Pull requests are welcome!
Please ensure that:

- your code is C99‑compliant
- the header‑only design is preserved
- all supported build systems continue to work
- the CI passes
- new functionality is documented using Doxygen

### 3. Code Style

- keep the code simple and readable
- avoid unnecessary macros
- follow consistent naming conventions
- use the provided LOG_* and ASSERT macros appropriately

### 4. Documentation

Documentation is generated using **Doxygen**.
Please document new functions directly in the header files.

## 🧪 Testing

There is no formal test suite yet, but please:

- compile example code
- verify all build systems work
- ensure CI remains green

## 🤝 Thank You

Every contribution helps strengthen the ya- ecosystem.
We appreciate your time and effort!
