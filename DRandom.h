#ifndef DRANDOM_CPP
#define DRANDOM_CPP

//Version 2.0

//Defines needed for random
#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

namespace utils
{

  /**
   * My Random Number Generator
   * Returns a uniform deviate in the interval (0,1).
   * Created By David Coss, 2008 based on "ran1" from Numerical Recipes in C 1992.
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
  };


}


#endif
