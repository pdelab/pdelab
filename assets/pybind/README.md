For mesh.cpp (mesh works)

c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) mesh.cpp -I/usr/include/eigen3 -I/usr/lib/python3/dist-packages/ffc/backends/ufc/  -o mesh$(python3-config --extension-suffix) -L/usr/lib/x86_64-linux-gnu/ -l:libdolfin.so

For assembly.cpp (this does not work)

c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) assembly.cpp -I/usr/include/eigen3 -I/usr/lib/python3/dist-packages/ffc/backends/ufc/  -o assembly$(python3-config --extension-suffix) -L/usr/lib/x86_64-linux-gnu/ -l:libdolfin.so