project('yahelpers', 'c', version: '0.1')

install_headers(
    ['assert.h', 'log.h', 'logconstants.h'],
    subdir: 'ya-ecosystem/helpers'
)

pkg = import('pkgconfig')

pkg.generate(
    name: 'yahelpers',
    description: 'Header-only debug utilities for the ya ecosystem',
    version: meson.project_version(),
    subdirs: 'ya-ecosystem/helpers'
)
