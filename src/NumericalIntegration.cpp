/**
 * 
 * This file is part of libdnstd, a C++ utility library
 * This may be downloaded at http://libdnstd.davecoss.com
 * 
 * Copyright 2007, 2010 David Coss, PhD
 *
 * libdnstd is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * libdnstd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with libdnstd.  If not, see <http://www.gnu.org/licenses/>.
 */
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
