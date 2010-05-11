#ifndef __NUMERICALINTEGRATION_CPP__
#define __NUMERICALINTEGRATION_CPP__

#include <math.h>

/**
 * Calculates simpson rule for f(x,y;m) within the limits a to b, where m is the integration argument.
 */
static double simpsonRule(double x, double y, double a, double b, double f(double x, double y, double m) );

/**
 * Calculates the Composite Simpson's Rule integral for f(x,y;m), within the limits a to b, with m as the integration argument. Integration is performed over 10000 steps.
 */
static double compSimpsonsRule(double x, double y, double a, double b, double f(double x, double y, double m) );

static double romberg(double func(double z), double a, double b);



#endif

