#include "NumericalIntegration.h"

 double simpsonRule(double x,double y, double a, double b, double f(double x, double y, double m))
 {
   double returnMe = f(x,y,a) + 4*f(x,y,(a+b)/2)+f(x,y,b);
   return returnMe*(b-a)/6;

 }

 double compSimpsonsRule(double x, double y, double a, double b, double f(double x, double y, double m))
 {

   double returnMe = f(x,y,a) + f(x,y,b);
   double n = 10000;
   double step = (b-a)/n;
   for(double i = 2;i<n;i += 2)
     {
       returnMe += 2*f(x,y,a+i*step);
     }

   for(double i = 1;i<n;i += 2)
     {
       returnMe += 4*f(x,y,a+i*step);
     }

   return returnMe*step/3;
 }
