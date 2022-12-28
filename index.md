# Teo language
A programming language for kids who want to get started!
Submission for NSC 2023 by Chitsanupong Rongpan (ชิษณุพงษ์ รองปาน).
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
<img src="./image.svg" width="100%"></img>

## Getting up and running
- Download lastest CI Artifacts on Github CI
- or, [compile](#compiling-with-cmake) yourself with ```cmake``` (Recommended)

## Compiling with CMake
Dependencies:
- git
- cmake
- make
- gcc (You can use clang by set the environment variable `CC="clang"` and `CXX="clang++"`
``` bash
git clone https://github.com/teolang/teo --depth=1 --recurse-submodules
cd teo
make release -C cparse
cmake . -B build
cd build && make
```
