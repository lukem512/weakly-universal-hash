// Illustration of the Ha,b set of weakly-universal hashing functions
// Luke Mitchell, 2013

#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
    // size of hash table
    const unsigned int m = 1024;

    // large prime
    // s.t. p > |U|
    const unsigned int p = 3571;

    std::cout << "Using table size of " << m << " with p = " << p << std::endl;

    // seed random
    srand(time(NULL));

    // "randomly" pick a, b
    // a is defined as being within the range 1 .. p - 1
    // b is defined as being within the range 0 .. p - 1
    unsigned int a = rand() % (p - 1) + 1;
    unsigned int b = rand() % p;

    std::cout << "Using a = " << a << " and b = " << b << std::endl;

    // perform hash!
    const unsigned int x = 55;

    // hab(x) = ((ax+b) % p) % m
    // where ax+b spreads the key amongst the table
    // the modulus by p prevents collisions, as there are no factors
    // the modulus by m ensures each value is within the table
    unsigned int result = ((a*x + p) % p) % m;

    std::cout << "Hashed value of " << x << " is " << result << std::endl;

    return 0;
}

