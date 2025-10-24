#include "header.h"

double model(double *radioactivity, double *time, int N, double point) {
    double result = 0.0;
    for (int i = 0; i < N; i++) {
        double exponent = exp(-time[i] / point);
        result += time[i] * exponent * (radioactivity[i] - exponent);
    }

    return result;
}

double nonlinear_equation(double *radioactivity, double *time, int N, double precision) {
    double left = precision;
    double right = precision;
    double decay_time = left, fc;

    while (model(radioactivity, time, N, right) > 0){
        right *= 2;
    }
    
    while ((right - left) > precision) {
        decay_time = (left + right) / 2.0;
        fc = model(radioactivity, time, N, decay_time);
        
        if (fc > 0) {
            left = decay_time;
        } else {
            right = decay_time;
        }
    } 
    return decay_time;
}

double linear_equation(double *radioactivity, double *time, int N) {
    double sum_t_squared = 0.0;
    double sum_t_times_one_minus_radioactivity = 0.0;
    
    for (int i = 0; i < N; i++) {
        sum_t_squared += time[i] * time[i];
        sum_t_times_one_minus_radioactivity += time[i] * (1.0 - radioactivity[i]);
    }
    
    return sum_t_squared / sum_t_times_one_minus_radioactivity;
}
