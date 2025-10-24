#include "header.h"

int experiment(double* radioactivity, double* time_arr, double start_time, double end_time, double step, double beta) {
    int count = 0;
    int N = floor((end_time - start_time) / step);

    for(double t = start_time; t <= end_time; t += step, count++){
        time_arr[count] = t;
        double exact_value = exp(-time_arr[count] / beta);
        radioactivity[count] = exact_value;
    }
    
    return N;
}

void add_noise(double* radioactivity, int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        double noise = ((double)rand() / RAND_MAX * 2.0 - 1.0)* 0.05;
        radioactivity[i] += noise;
    }
    return;
}