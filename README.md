# SML
A language for doing secure machine learning

## Packages to be installed
- python3
- antlr4
- **TODO:** what else do we need, and how can we install them?

## How to generate *.cpp from *.sml?
```
cd sml/src/
./run.sh ../examples/test.sml
```
This will generate `sml/examples/test.cpp`.

## How to run *.cpp on ABY?
Delete `aby-cbmc-gc`:
```
rm -rf ABY/src/examples/aby-cbmc-gc/
```

Edit `ABY/src/examples/millionaire_prob/common/millionaire_prob.cpp`:
- Change the line below `// my code` to `#include "[path-to-cpp-file]/test.cpp"`
  (e.g., to `#include "/home/wonyeol/sml/examples/test.cpp"`)
  
Compile ABY:
```
cd ABY/; make cleanall; make
```

Run ABY:
```
cd ABY/bin
./millionaire_prob.exe -r 0  # start server
./millionaire_prob.exe -r 1  # start client
```
