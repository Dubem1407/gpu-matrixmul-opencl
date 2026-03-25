
/* kernel.cl 
 * Matrix multiplication
 * Device code.
 * Check out vectorAdd.cl as an example...
 */
 
// OpenCL Kernel
__kernel void matrixMul(__global float* C, __global float* A, __global float* B, int HA, int WA, int HB, int WB)
{
	int row = get_global_id(1); 
    int col = get_global_id(0);

    if (row < HA && col < WB) {
        C[row * WB + col] = 0;
        for (int k = 0; k < HB; k++) {
            C[row * WB + col] += A[row * WA + k] * B[k * WB + col];
        }
    }
}

