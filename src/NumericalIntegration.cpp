#include "NumericalIntegration.h"

 double compSimpsonsRule(double a, double b, double *integration_parameters, double f(double* variable, double* parameters))
 {

   double returnMe = f(&a,integration_parameters) + f(&b,integration_parameters);
   static const double n = 10000;
   double step = (b-a)/n;
   double variable;
   for(double i = 2;i<n;i += 2)
     {
	   variable = a+i*step;
       returnMe += 2*f(&variable,integration_parameters);
     }

   for(double i = 1;i<n;i += 2)
     {
	   variable = a+i*step;
       returnMe += 4*f(&variable,integration_parameters);
     }

   return returnMe*step/3;
 }
