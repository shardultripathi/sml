# SML
A language for doing secure machine learning

## Packages to be installed
- python3
- antlr4 with python3 runtime
- ABY
- **TODO:** what else do we need, and how can we install them?

## How to generate *.cpp from *.sml?
```
cd sml/src/
./run.sh ../examples/test.sml <y/b> <0/1>
```
This will generate `sml/examples/test.cpp`.

## Getting started with ABY
Delete `aby-cbmc-gc`:
```
rm -rf ABY/src/examples/aby-cbmc-gc/
```
Compile ABY:
```
cd ABY/; make cleanall; make
```

## How to run *.cpp on ABY?
Use the file `millionaire_prob.cpp` in examples folder in our repo.
Edit `ABY/src/examples/millionaire_prob/common/millionaire_prob.cpp`:
- Change the line below `// my code` to `#include "[path-to-cpp-file]/test.cpp"`
  (e.g., to `#include "/home/wonyeol/sml/examples/test.cpp"`)

Compile new millionaire file:
- change directory to `ABY/src/examples/millionaire_prob/`
- `make clean`
- `make`

Run ABY:
Change directory to `ABY/bin`
```
./millionaire_prob.exe -r 0  # start server
./millionaire_prob.exe -r 1  # start client
```
