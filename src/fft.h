#define __DEBUG__ 1

#ifndef FFT_CPP
#define FFT_CPP

//std lib stuff
#include <math.h>
#include <iostream>
#include <complex>

#ifndef ushort
#include <stdlib.h>
#endif

//FFTW stuff
#include <fftw3.h>//put AFTER #include <complex>

#ifdef __DEBUG__
#define DEBUG_PRINT(x) std::cout << x << std::endl;
#else
#define DEBUG_PRINT(x)
#endif

namespace math{

  class FFT
  {

  public:


    /**
     * Takes a given complex double array and replaces it with its Discrete Fourier Transform
     *
     * @param data double complex array of size 2*size.
     * @param size number of COMPLEX NUMBERS
     * @param isign 1 for Fourier Transform, -1 for inverse transform
     * @param flag unsigned Flag for the FFTW fftp (either FFTW_MEASURE or FFTW_ESTIMATE(default))
     */
    static void discrete(std::complex<double> * data, ushort size, int isign, unsigned flag = FFTW_ESTIMATE);

    /****
     ***
     *TO BE FINISHED
     */
#if 0

    /**
     * Swaps the vales of data[x] and data[y]
     *
     * @param data double array
     * @param x element to switch
     * @param y element to switch
     */
    static void swap(double * data, ushort x, ushort y);	

    /**
     * Performs the DFT of 2 real arrays simultaneously.
     *
     * In this case, unlike discrete(...), the fft values do not replace the original data. Instead, arrays must be supplied as parameters to store the results.
     *
     * @param data1 real double array
     * @param data2 real double array
     * @param fft1 complex double array FFT of data1
     * @param fft2 complex double array FFT of data2
     * @param size integer size of data1 and data2 (# of complex numbers in fft1 and fft2)
     * @see void discrete()
     */
    static void twofft(double * data1, double * data2, double * fft1 , double * fft2, ushort size);

    /**
     * Convolves 2 functions.
     *
     * S is the "signal" function and R is the "Response" function.
     */
    static void convolve(double * R, ushort Rsize, double * S, ushort Ssize, int isign, double * result,double * dummy);

    /**
     * Performs a DFT on a real array of data
     * @see void discrete()
     */
    static void realfft(double * data, ushort complexSize, int isign);

#endif
    /**TO BE FINISHED
    */

    /**
     * Takes data and replaces it with it's N-Dimensional Discrete Fourier Transform.
     *
     * @param data array of size ndim*max(nn)*2. The resulting data is a complex array.
     * @param nn Unsigned Long Array containing the complex length of each dimension. Each must be a power of 2.
     * @param ndim int size of nn array.
     * @param isign. 1 for Fourier Transform, -1 for Inverse Fourier Transform.
     */
    static void ndim_discrete(std::complex<double> * data, int * nn, int ndim, int isign,unsigned flag = FFTW_ESTIMATE);

    /***
     **
     * TO BE FINISHED
     */
#if 0

    /**
     * Pads the given array up to the next power of 2 with zeros.
     *
     * @param array array of size N.
     * @param N int size of array.
     * @return double * size of new array is the next power of 2 above N
     */
    static double * pad(double * array, int N);

    /**
     * Unpads the given array down to the next lower power of 2.
     *
     * @param array array of size N.
     * @param N int size of array.
     * @return double * size of new array is the next lower power of 2 below N
     */
    static double * unpad(double * array, int N);
    
    /***FINISH THIS */
#endif
	 
  };//end class FFT

}//end namespace math
#endif

