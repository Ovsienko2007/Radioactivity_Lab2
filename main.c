#include "header.h"


int main() {
    double const start_time =  0.0;
    double const end_time =  9.9;
    double const step =  0.1;

    double const precision = 0.001;
    double const betta = 3.0;

    double const interval1 = 0.2;
    double const interval2 = 8.2;

    double radioactivity[maxN];
    double time[maxN];

    printf("Inicialisation complited\n");

    //Подготовка данных
    int N = experiment(radioactivity, time, start_time, end_time, step, betta);
    add_noise(radioactivity, N);
    printf("Data was generated\n");

    double decay_time = nonlinear_equation(radioactivity, time, N, precision);
    double decay_rate = linear_equation(radioactivity, time, N);
    printf("Data was analised\n");

    double time_start = precision_analysis(radioactivity, time, N, precision);

    double decay_time_div = dev_exp(radioactivity, time, N, decay_time);
    double decay_rate_div = dev_linear(radioactivity, time, N, decay_rate);
    printf("Data was preparated\n");

    printf("%.4lf +- %.4lf\n", decay_time, decay_time_div);
    printf("%.4lf +- %.4lf\n", decay_rate, decay_rate_div);
    printf("%lg\n", time_start);
    return 0;
}
