#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Compute vector sum C_h = A_h + B_h
void vecAdd(float* A_h, float* B_h, float* C_h, int n) {
  for (int i = 0; i < n; ++i) {
    C_h[i] = A_h[i] + B_h[i];
  }
}

int main() { // Memory allocation for arrays A, B, and C
  const int N = 100000;

  float *A = malloc(N * sizeof(float));
  float *B = malloc(N * sizeof(float));

  srand(time(NULL));
  for (int i = 0; i < N; ++i) {
    A[i] = (rand() + 0.f) / RAND_MAX;
  }
  for (int i = 0; i < N; ++i) {
    B[i] = (rand() + 0.f) / RAND_MAX;
  }
  
  float *C = malloc(N * sizeof(float));

  // I/O to read A and B, N elements each
  vecAdd(A, B, C, N);

  float sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += C[i];
  }

  printf("Total: %f\n", sum);
}
