#!/usr/bin/env python
import os
from distutils.core import setup, Extension
sources = [
    'src/python/core.c',
    'src/libethash/io.c',
    'src/libethash/internal.c',
    'src/libethash/sha3.c']
if os.name == 'nt':
    sources += [
        'src/libethash/util_win32.c',
        'src/libethash/io_win32.c',
        'src/libethash/mmap_win32.c',
    ]
else:
    sources += [
        'src/libethash/io_posix.c'
    ]
depends = [
    'src/libethash/ethash.h',
    'src/libethash/compiler.h',
    'src/libethash/data_sizes.h',
    'src/libethash/endian.h',
    'src/libethash/ethash.h',
    'src/libethash/io.h',
    'src/libethash/fnv.h',
    'src/libethash/internal.h',
    'src/libethash/sha3.h',
    'src/libethash/util.h',
]
pyethash = Extension('pyethash',
                     sources=sources,
                     depends=depends,
                     extra_compile_args=["-Isrc/", "-std=gnu99", "-Wall"])

setup(
    name='pytethashv1',
    author="Trustfarm",
    author="Matthew Wampler-Doty",
    author_email="info@tao.foundation",
    author_email="matthew.wampler.doty@gmail.com",
    license='GPL',
    version='0.1.23',
    url='https://github.com/tao-foundation/tethashv1',
    download_url='https://github.com/tao-foundation/tethashv1/tarball/v11',
    description=('Python wrappers for tethashv1, the TAO TEO TEthashV1 proof of work'
                 'hashing function'),
    ext_modules=[pytethashv1],
)
