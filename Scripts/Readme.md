Compiling and Running Benchmarks
====

Installation
----
In order to install BOEHM GC on mac, if you have mac-brew installed, you can run the following command:

`brew install bdw-gc`

Compilation
----
In order to compile the generated C code and handwritten C++ code use the following commands:

```
./compile_c.sh
./compile_cpp.sh
```

Running
----

In order to run the micro benchmarks use the following command:

```
./run_micro.sh
```

To run the Bundle Adjustment, GMM, and Hand Tracking benchmarks use the following command:

```
./run.sh
```