#include "DRandom.h"

namespace utils
{



  DRandom::DRandom()
  {
    rng = new MTRand();
    mySeed = new long();
    *mySeed = 42;
  }

  DRandom::~DRandom()
  {
    delete rng; rng = 0;
    delete mySeed; mySeed = 0;
  }

  double DRandom::random()
  {
    if(rng == 0)
      rng = new MTRand();
    
    return rng->randDblExc();
  }

  long DRandom::changeSeed(long seed)
  {
    long returnMe = 0;
    if(mySeed != 0)
      returnMe = *mySeed;
    if(rng == 0)
      rng = new MTRand();

    rng->seed(seed);
    return returnMe;
  }


}
