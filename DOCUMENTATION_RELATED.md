# Documentation

The documentation is generated using **Doxygen**.

- 📘 **HTML Documentation:**
  <https://asaeppel4231.github.io/yahelpers/>

<!-- 📄 **PDF Documentation:**
  <https://asaeppel4231.github.io/yahelpers/pdf/yahelpers.pdf>
-->

## Building the documentation locally

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
