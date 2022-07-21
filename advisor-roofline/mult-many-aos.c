#include <stdio.h>
#include <omp.h>

#define REPEAT  10000
#define N       2048

typedef struct aos {
  double x;
  double y;
  double z;
} aos;

int main(int argc, char **argv)
{
  aos d[N];
  double c = 0.3141; // chosen by fair dice roll
  int i, j;

  for (i=0; i<N; i++) {
    d[i].x = i + c;
    d[i].y = i + c;
    d[i].z = i + c;
  }

  double time = omp_get_wtime();
  for (j=0; j<REPEAT; j++) {
//    #pragma omp parallel for simd schedule(simd: static)
    #pragma omp parallel for
    for (i=1; i<N; i++) {
      d[i].z = d[i].x + d[i].y + 2.0*d[i].x + 4.0*d[i].x + 4.0*d[i].y + c*d[i].x + c*d[i].y + (d[i].y + d[i].x);
    }
  }
  time = omp_get_wtime() - time;
  printf("%fs", time);
}
