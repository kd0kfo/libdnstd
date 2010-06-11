#include "fft.h"

void math::FFT::discrete(std::complex<double> * data, ushort size, int isign, unsigned flag)
{
  fftw_complex *in,*out;
  fftw_plan p;
  
  //assign data and allocate memory
  in = reinterpret_cast<fftw_complex*>(data);
  out = new fftw_complex[size];
  
  //make the plan
  p = fftw_plan_dft_1d(size,in,out,isign,flag);
  
  //Run fft
  fftw_execute(p);
  
  //clean up
  fftw_destroy_plan(p);
  for(int i = 0;i<size;i++)
	data[i] = std::complex<double>(out[i][0],out[i][1]);

  delete [] out;
      
}


void math::FFT::ndim_discrete(std::complex<double> * data, unsigned long * nn, int ndim, int isign,unsigned flag)
{
  fftw_complex *in,*out;
  fftw_plan p;
  
  unsigned long size = 1;
  for(int i =0;i<ndim;i++)
	size *= nn[i];
  
  //assign data and allocate memory
  in = reinterpret_cast<fftw_complex*>(data);
  out = new fftw_complex[size];
  
  //make the plan
  p = fftw_plan_dft(ndim,nn,in,out,isign,flag);
  
  //Run fft
  fftw_execute(p);
  
  //clean up
  fftw_destroy_plan(p);
  
  for(int i = 0;i<size;i++)
	data[i] = std::complex<double>(out[i][0],out[i][1]);

  delete [] out;
}
