#include "DRandom.h"

namespace utils
{



  DRandom::DRandom()
  {
    mySeed = new long;
    changeSeed(42L);
    random();
  }

  DRandom::~DRandom()
  {
  
  }

  double DRandom::random()
  {
    int j;
    long k;
    static long iy=0;
    static long iv[NTAB];
    float temp;

    if(*mySeed <= 0 || !iy)
      {
	if(-(*mySeed) < 1)
	  *mySeed = 1;
	else
	  *mySeed = -(*mySeed);
	
	for(j=NTAB+7;j>=0;j--)
	  {
	    k=(*mySeed)/IQ;
	    *mySeed=IA*(*mySeed - k*IQ)-IR*k;
	    if(*mySeed < 0)
	      *mySeed += IM;
	    if(j<NTAB)
	      iv[j] = *mySeed;
	    
	  }
	iy = iv[0];
      }
    
    k = (*mySeed)/IQ;
    *mySeed = IA*(*mySeed - k*IQ)-IR*k;
    if(*mySeed < 0)
      *mySeed += IM;
    j = iy/NDIV;
    iy = iv[j];
    iv[j] = *mySeed;
    if((temp = AM*iy) > RNMX)
      return RNMX;
    else
      return temp;
  }

  long DRandom::changeSeed(long seed)
  {
    int returnMe = *mySeed;
    *mySeed = -1L*seed;
    return -1L*returnMe;
  }


}
