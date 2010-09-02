#ifndef DRANDOM_CPP
#define DRANDOM_CPP

#include "MersenneTwister.h"

namespace utils
{

  /**
   * Random Number Generator
   * Uses MerseeneTwister.h (see that file for its copyright notice).
   * This class was originally created but was not GPL compliant.
   * For backwards-compatibility with applications that still use DRandom, 
   * this file is included, acting as a wrapper for a GPL compliant 
   * random number generator. With that in mind, MTRand should be
   * used directly in the future.
   *
   * Created By David Coss, 2010
   * Copying and distributing are permitted under the terms of the GNU Public License version 3(see COPYING or http://www.gnu.org/licenses/gpl.txt).
   */
  class DRandom{

  public:

    /**
     * Main (only) constructor.
     * @see changeSeed(int seed)
     */
    DRandom();

    /**
     * Destructor.
     */
    ~DRandom();

    /**
     * Gives a random double.
     * @return integer
     */
    double random();

    /**
     * Changes the seed to the provided value
     * Must be a positive integer.
     * @param seed new seed.
     * @return int
     */
    long changeSeed(long seed);

  private:	
    long * mySeed;
    MTRand * rng;
  };


}


#endif
