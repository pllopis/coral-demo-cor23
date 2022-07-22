#include <stdio.h>
#include <omp.h>

#define REPEAT  1000
#define N       8388608

double x[N], y[N], z[N];
double c = 0.3141; // chosen by fair dice roll
int i, j;

void init_arrays() {
  for (i=0; i<N; i++) {
    x[i] = i;
    y[i] = i;
    z[i] = i;
  }
}

void compute_something(int i, int j) {
  z[i] = x[i] + 2*x[i-1] + 4*i*x[i-1] + c*(x[i-1] + c*y[i] + 4*y[i]) + i*y[i-1] + c*y[i];
}

void compute_arrays() {
  for (j=0; j<REPEAT; j++) {
    #pragma omp parallel for
    for (i=0; i<N; i++) {
      compute_something(i, j);
    }
  }
}

int main(int argc, char **argv)
{
  init_arrays();

  double time = omp_get_wtime();
  compute_arrays();
  time = omp_get_wtime() - time;

  printf("%fs", time);
}
