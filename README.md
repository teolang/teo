# Teo
A programming language for kids designed to be fast and easy to learn.

A submission for NSC 2023 by Chitsanupong Rongpan

## Getting up and running
- Download lastest CI Artifacts on Github CI
- or, [compile](#compiling-with-cmake) yourself with ```cmake```

## Compiling with CMake
```bash
git clone https://github.com/teolang/teo --depth=1 --recurse-submodules
cd teo
make release -C cparse
cmake . -B build
cd build && make
```
