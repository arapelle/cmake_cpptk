# `cmake_cpptk`

A C++ library which provides a basic usage of CMake and CTest CLI tools.

# Install #
## Requirements ##

Binaries:

- A C++20 compiler (ex: g++-14)
- CMake 3.30 or later

Testing Libraries (optional):

- [Google Test](https://github.com/google/googletest) 1.14 or later (optional)

## Clone

```
git clone https://github.com/arapelle/cmake_cpptk
```

## Install with `conan`

Create the conan package.
```
conan create . --build=missing -c
```
Add a requirement in your conanfile project file.
```python
    def build_requirements(self):
        if not self.conf.get("tools.build:skip_test", default=True):
            self.test_requires("cmake_cpptk/0.1.0")
```

## Install with `CMake`

```
cd cmake_cpptk
cmake .
cmake --install .
```

# License

[MIT License](./LICENSE) © cmake_cpptk
