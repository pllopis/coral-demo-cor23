#include <stdio.h>
#include <omp.h>

#define REPEAT  1000
#define N       8388608

int main(int argc, char **argv)
{
  double x[N], y[N], z[N];
  double c = 0.3141; // chosen by fair dice roll
  int i, j;

  for (i=0; i<N; i++) {
    x[i] = i + c;
    y[i] = i + c;
    z[i] = i + c;
  }

  double time = omp_get_wtime();
  for (j=0; j<REPEAT; j++) {
    #pragma omp parallel for
    for (i=0; i<N; i++) {
      z[i] = x[i] + y[i];
    }
  }
  time = omp_get_wtime() - time;
  printf("%fs", time);
}
