#include <stdio.h>

__global__ void vecadd(float *out, float* a, float* b, int n) {
	for(int i = 0; i < n; i++) {
		out[i] = a[i] + b[i];
	}
}

int main() {
	const int N = 1000;
	float *a, *b, *out;
	float *d_a;
	a = (float*) malloc(1000*sizeof(float));
	cudaMalloc((void**)&d_a, 1000*sizeof(float));
	cudaMemcpy(d_a, a, sizeof(float) * N, cudaMemcpyHostToDevice);
	vecadd<<<1,1>>>(out, d_a, b, 1000);
	cudaFree(d_a);
	free(a);
}