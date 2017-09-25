# parallel_armadillo

Benchmark code and results for parallelizing the diagonalization of matrices using armadillo.


## Dependencies
[![armadillo Dependency](https://img.shields.io/badge/eigen-8+-blue.svg)](http://arma.sourceforge.net)
[![MKL Dependency](https://img.shields.io/badge/MKL-2018-blue.svg)](https://software.intel.com/en-us/mkl)


## Goal

The goal of this project is to find out some timings of full diagonalizations of large, symmetric matrices using the armadillo library, on my machine. Specifications:
 * MacBook Pro, mid 2015
 * Processor: 2,5 GHz Intel Core i7 (4 cores, 256KB L2, 6 MB L3)
 * 16 GB 1600 MHz DDR3
 * Intel Iris Pro 1536 MB VRAM

C++ Compiler:
 * (MacPorts gcc49 4.9.4_2) 4.9.4


## Timings

### Preliminary testings
With standard armadillo, we get the following timings (in seconds). Armadillo automatically enables OpenMP:

    50 : 0.00419
    100 : 0.001029
    250 : 0.004986
    500 : 0.021301
    1000 : 0.099476
    2500 : 1.44927
    5000 : 13.0289
    10000 : 164.181


### `-01` compiler flag
Using the `-01` compiler flag, we get the following timings:

    50 : 0.000217
    100 : 0.000885
    250 : 0.005373
    500 : 0.022267
    1000 : 0.106715
    2500 : 1.59232
    5000 : 13.3628
    10000 : 170.674



### `-O2` compiler flag
Using the `-O2` compiler flag, we get the following results:

    50 : 0.000223
    100 : 0.001011
    250 : 0.005317
    500 : 0.021279
    1000 : 0.106962
    2500 : 1.58473
    5000 : 12.8927
    10000 : 164.331


### `-O3` compiler flag
Using the `-O3` compiler flag, we get the following results:

    50 : 0.000211
    100 : 0.000993
    250 : 0.004822
    500 : 0.021878
    1000 : 0.098428
    2500 : 1.65663
    5000 : 13.3471
    10000 : 162.549

### Accelerate and `-O2`
Using the Accelerate (macOS) framework, we get the following timings:

    50 : 0.00021
    100 : 0.000957
    250 : 0.004876
    500 : 0.021395
    1000 : 0.096768
    2500 : 1.53004
    5000 : 12.3652
    10000 : 158.362


### Sparse matrices & Accelerate and `-O2`

    1000 : 0.177537
    2500 : 1.2949
    5000 : 8.53172
    10000 : 85.7126
