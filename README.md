<p align="center">
  <a href="https://teolang.github.io/teo">
    <picture>
      <img src="./logo.png" height="128">
    </picture>
    <h1 align="center">Teo</h1>
  </a>
</p>

<img align="left" src="./image.svg" width="60%"></img>
A programming language for kids designed to be fast and easy to learn.

Teo is an easy-to-learn programming language for children.
Because there are so many concepts and commands to master, I believe it is difficult to learn the concept of programming.
Abstraction is wonderful, but it may be the source of much confusion for newcomers because it demands them to think about the system at a high level. In some circumstances, reducing abstraction can help beginners understand better.

## Getting up and running
- Download lastest [CI Artifacts](https://github.com/teolang/teo/actions/workflows/c-cpp.yml) on Github CI
- or, [compile](#compiling-with-cmake) yourself with `cmake` (Recommended)

## Compiling with CMake
Dependencies:
- Git
- CMake
- Make
- GNU Compiler Collection (You can use CLANG+LLVM by set the environment variable `CC=clang` and `CXX=clang++`)
- GTK3 (Runtime dependencies) [Windows users don't need to install this if they download from the CI Artifacts]
```bash
git clone https://github.com/teolang/teo --depth=1 --recurse-submodules
cd teo
make release -C cparse
cmake . -B build
cd build && make
```
