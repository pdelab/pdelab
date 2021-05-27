from distutils.core import setup, Extension

setup(
    name = 'example',
    version = '0.1',
    author = "SWIG Docs",
    description = "Simple swig example from docs",
    ext_modules = [
        Extension(
            '_example',
            sources=['example_wrap.cxx', 'example.cpp'],
            swig_opts=["-c++"],
            library_dirs=['/usr/lib/x86_64-linux-gnu/'],
            libraries=['dolfin'],
            include_dirs=[
                '/usr/include/x86_64-linux-gnu/python3.8/',
        		'/usr/lib/python3/dist-packages/ffc/backends/ufc/',
        		'/usr/include/eigen3',
        		'/usr/local/include/',
            ],
        ),
    ],
    py_modules = ["example"],
)
