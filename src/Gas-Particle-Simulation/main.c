#include <stdio.h>
#include <openacc.h>

#define N 1000

void simulate(float *pos, float *vel, int n) {
    #pragma acc kernels loop independent
    for (int i = 0; i < n; i++) {
        pos[i] += vel[i];
        vel[i] += 0.01;
    }
}

int main() {
    float pos[N], vel[N];

    #pragma acc parallel loop independent
    for (int i = 0; i < N; i++) {
        pos[i] = i;
        vel[i] = 0.1;
    }

    simulate(pos, vel, N);

    #pragma acc parallel loop independent
    for (int i = 0; i < N; i++) {
        printf("%f %f\n", pos[i], vel[i]);
    }

    return 0;
}