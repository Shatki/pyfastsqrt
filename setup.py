#!/usr/bin/env python
from distutils.core import setup
from distutils.extension import Extension

pyfastsqrt_module = Extension(name='pyfastsqrt', sources=['pyfastsqrt.c'])
setup(name='pyfastsqrt',
      author='Seliverstov Dmitriy 2016 shatki@mail.ru',
      version='1.0',
      ext_modules=[pyfastsqrt_module])