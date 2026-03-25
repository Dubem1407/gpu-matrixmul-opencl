# OpenCL Matrix Multiplication: CPU vs GPU

This project compares CPU and GPU implementations of matrix multiplication using C and OpenCL. It was originally developed as part of coursework in Digital Systems Architecture and later refined to better document GPU execution, benchmarking, and reproducibility.

## Overview

The project includes:
- A CPU baseline implementation of matrix multiplication in C
- An OpenCL GPU implementation with host-side setup and kernel execution
- An OpenCL device query utility for inspecting device capabilities
- Benchmark documentation comparing CPU and GPU execution

## Technical Concepts Demonstrated

- Host-device programming model in OpenCL
- GPU kernel execution using work-items and workgroups
- CPU vs GPU performance scaling
- Parallel execution and workload distribution
- Device capability inspection such as compute units, workgroup sizes, and memory characteristics
- Performance considerations including kernel launch and memory transfer overhead

## Repository Structure

- `src/deviceQuery.c` - queries OpenCL platform and device capabilities
- `src/matrixMul.c` - CPU matrix multiplication baseline
- `src/matrixmul_host.c` - OpenCL host code for GPU execution
- `src/matrixmul_kernel.cl` - OpenCL kernel
- `docs/lab-report.pdf` - lab report with methodology and benchmark results

## Example Results

From the benchmark report:

| Matrix Size | CPU Time (ms) | GPU Time (ms) |
|------------|--------------:|--------------:|
| 4x4        | 0.012         | 175.437       |
| 8x8        | 0.025         | 183.516       |
| 64x64      | 1.176         | 225.694       |
| 512x512    | 496.504       | 197.043       |
| 1024x1024  | 4142.730      | 75.763        |
| 2048x2048  | 45994.660     | 643.079       |

These results show that the GPU implementation becomes much more advantageous as matrix size increases, while smaller problem sizes are more affected by host-device transfer and kernel launch overhead.

## Requirements

- C/C++ compiler
- OpenCL headers and runtime/library for the target platform
- Linux or Windows environment with OpenCL properly installed

## Build

Compile from the repository root:

```bash
g++ -o matrixMul src/matrixMul.c
g++ -o deviceQuery src/deviceQuery.c -lOpenCL
g++ -o matrixmul_host src/matrixmul_host.c -lOpenCL

## Run

Examples:
./matrixMul 1024
./deviceQuery
./matrixmul_host 1024

If no size argument is provided, the matrix multiplication programs use a default square matrix size.

## What I Learned

This project strengthened my understanding of:

GPU vs CPU execution models
Parallel performance scaling
Work-item and workgroup mapping
The impact of memory transfer and launch overhead on GPU performance
Why larger workloads benefit more from data-parallel execution

## Notes

The OpenCL portion of this project was developed from course lab work and then further refined by improving code organization, usability, and documentation for clearer reproducibility and presentation.