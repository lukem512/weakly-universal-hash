// Demonstrative project illustrating the weakly-universal Hp,m set of hashing functions
// Luke Mitchell, 2013

#include <iostream>
#include <cstdlib>
#include <cstring>

class hpmhash
{
  public:
  // Picks a value for a
  // where a must be within the range 1 .. p - 1
  static unsigned int a(const unsigned int m, const unsigned int p)
  {
      return rand() % (p - 1) + 1;
  }

  // Picks a value for b
  // where b must be within the range 0 .. p - 1
  static unsigned int b(const unsigned int m, const unsigned int p)
  {
      return rand() % p;
  }

  // Performs the hab hashing algorithm
  // x is the integer version of the value to be hashed
  static unsigned int hash(const unsigned int m,
                           const unsigned int p,
                           const unsigned int a,
                           const unsigned int b,
                           const unsigned int x)
  {
      return (a*x + b % p) % m;
  }
};

int main (int argc, char** argv)
{
    // Universe
    const char* U = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // Table size
    const unsigned int m = 1024;
    
    // Prime number, larger than |U|
    const unsigned int p = 67;

    if (p < strlen(U))
    {
        std::cerr << "Prime must be larger than the universe" << std::endl;
        return -1;
    }

    // "Randomly" select a hashing function
    srand(time(NULL));

    unsigned int a = hpmhash::a(m,p);
    unsigned int b = hpmhash::b(m,p);

    std::cout << "Using algorithm h" << a << "," << b << std::endl;

    // Define an input
    const char x = 'x';

    // Hash it!
    unsigned int result = hpmhash::hash(m,p,a,b,(unsigned int)x);

    std::cout << "Hashed value of " << x << " is " << result << std::endl;

    return 0;
}
