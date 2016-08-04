from distutils.core import setup, Extension

bitops = Extension('bitops',
                    sources = ['bitops.c'])

setup (name = 'bitops',
       version = '1.0',
       description = 'Efficient bitwise operators',
       ext_modules = [bitops])
