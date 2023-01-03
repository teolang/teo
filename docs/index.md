# Teo language
A programming language for kids who want to get started!
<img src="./image.svg" width="100%"></img>
## Some examples:
```
let x 5;
print x;
```

```
let x 2;
assert x < 4 3;
end;
```

## Getting up and running
- Download lastest [CI Artifacts](https://github.com/teolang/teo/actions/workflows/c-cpp.yml) on Github CI
- or, [compile](#compiling-with-cmake) yourself with ```cmake``` (Recommended)

## Compiling with CMake
Dependencies:
- Git
- CMake
- Make
- GNU Compiler Collection (You can use clang by set the environment variable `CC="clang"` and `CXX="clang++"`
``` bash
git clone https://github.com/teolang/teo --depth=1 --recurse-submodules
cd teo
make release -C cparse
cmake . -B build
cd build && make
```
