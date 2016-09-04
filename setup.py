#!/usr/bin/env python
from distutils.core import setup
from distutils.extension import Extension

pyfastsqrt_module = Extension(name='pyfastsqrt', sources=['pyfastsqrt.c'])
setup(name='pyfastsqrt', ext_modules=[pyfastsqrt_module])