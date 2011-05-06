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
