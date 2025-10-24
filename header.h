#ifndef HEADERS_H_
#define HEADERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int experiment(double* radioactivity, double* time_arr, double start_time, double end_time, double step, const int beta);
void add_noise(double* radioactivity, int N);

double model(double *radioactivity, double *time, int N, double point);
double nonlinear_equation(double *radioactivity, double *time, int N, double precision);
double linear_equation(double *radioactivity, double *time, int N);

double dev_exp(double *radioactivity, double *time, int M, double decay_time);
double dev_linear(double *radioaktivity, double *time, int M, double decay_rate);
double precision_analysis (double *radioactivity, double *time, int N, double precision);

#endif