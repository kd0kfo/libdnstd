#ifndef NUMERICALINTEGRATION_H
#define NUMERICALINTEGRATION_H

/**
 * Takes limits of integration (a,b) and calculations the integral:
 * \int^b_a f(x;integration_parameters)dx
 */
double compSimpsonsRule(double a, double b, double *integration_parameters, double f(double* variable, double* parameters));
#endif

