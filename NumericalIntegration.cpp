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


double romberg(double func(double z), double a, double b)
{
  double h = b - a;     // coarsest panel size
  double dR;			      // convergence
  int np = 1;           // Current number of panels
  const int N = 25;     // maximum iterations
  double prec = 1e-8;	  // desired precision
  double * R = new double[N*N];

  for(int i = 0;i<N*N;i++)
    R[i] = 0;

  // Compute the first term R(1,1)
  R[0] = h/2 * (func(a) + func(b));

  // Loop over the desired number of rows, i = 2,...,N
  int i,j,k;
  for( i=1; i<N; ++i )
  {
    // Compute the summation in the recursive trapezoidal rule
    h /= 2.0;          // Use panels half the previous size
    np *= 2;           // Use twice as many panels
    double sumT = 0.0;
    for( k=1; k<=(np-1); k+=2 ) 
      sumT += func( a + k*h);

    // Compute Romberg table entries R(i,1), R(i,2), ..., R(i,i)
    R[N*i] = 0.5 * R[N*(i-1)] + h * sumT;   
    int m = 1;
    for( j=1; j<i; ++j )
    {
      m *= 4;
      R[N*i+j] = R[N*i+j-1] + (R[N*i+j-1] - R[N*(i-1)+j-1]) / (m-1);
    }
    dR = (j > 1) ? R[N*i+j-1] - R[N*(i-1)+(j-2)] : R[0];
    if (fabs(dR) < prec)
      return R[N*i+j-1];
  }
  return R[N*N-1];
}

