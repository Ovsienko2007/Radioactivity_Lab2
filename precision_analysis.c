#include "header.h"

double precision_analysis (double *radioactivity, double *time, int N, double precision)
{
    int i = 10;
    double decay_time = 0, decay_rate = 0;
    double deviation1 = 0, deviation2 = 0;
    double quotient = 0, time_start = 0; 
    for (i = 10; i < N + 1; i++)
    {
        decay_time = nonlinear_equation (radioactivity, time, i, precision);
        decay_rate = linear_equation (radioactivity, time, i);
        deviation1 = dev_exp(radioactivity, time, i, decay_time);
        deviation2 = dev_linear(radioactivity, time, i, decay_rate);
        quotient = deviation1 / deviation2;
        if (quotient > 2)
        {
            time_start = time[i-1];
            break;
        }
    }
    
    return time_start;
}


double dev_exp(double *radioactivity, double *time, int M, double decay_time)
{
    int i = 0;
    double sum_residuals1 = 0, deviation1 = 0;
    for (i = 0; i < M; i++)
    {
        sum_residuals1 += pow((radioactivity[i] - exp(-time[i] / decay_time)), 2);
    }
    deviation1 = sqrt(sum_residuals1) / M;
    return deviation1;

}

double dev_linear(double *radioactivity, double *time, int M, double decay_rate)
{
    int i = 0;
    double sum_residuals2 = 0, deviation2 = 0;
    for (i = 0; i < M; i++)
    {
        sum_residuals2 += pow((radioactivity[i] - 1 + time[i] / decay_rate), 2);
    }
    deviation2 = sqrt(sum_residuals2) / M;
    return deviation2;
}
