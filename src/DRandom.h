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
