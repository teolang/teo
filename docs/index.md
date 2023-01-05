# Teo language
<img align="left" src="./image.svg" width="60%"></img>
A programming language for kids designed to be fast and easy to learn.

Teo is an easy-to-learn programming language for children. Because there are so many concepts and commands to master in normal programming language, I believe it is difficult to learn the concept of it. Abstraction is wonderful, but it can be the source of much confusion for newcomers because it demands them to think about the system at a high level. In some circumstances, reducing abstraction can help beginners understand better.


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
