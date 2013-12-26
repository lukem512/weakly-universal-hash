// Illustration of the Ha,b set of weakly-universal hashing functions
// Luke Mitchell, 2013

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(int argc, char** argv)
{
    // Universe
    const char* U = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // size of hash table
    const unsigned int m = 1024;

    // large prime
    // s.t. p > |U|
    const unsigned int p = 67;

    if (p < strlen(U))
    {
        fprintf(stderr,"Prime must be larger than the universe");
        return -1;
    }

    printf ("Using table size of %d with p = %d\n",m,p);

    // seed random
    srand(time(NULL));

    // "randomly" pick a, b
    // a is defined as being within the range 1 .. p - 1
    // b is defined as being within the range 0 .. p - 1
    unsigned int a = rand() % (p - 1) + 1;
    unsigned int b = rand() % p;

    printf ("Using a = %d and b = %d\n",a,b);

    // perform hash!
    const char x = 'x';

    // hab(x) = ((ax+b) % p) % m
    // where ax+b spreads the key amongst the table
    // the modulus by p prevents collisions, as there are no factors
    // the modulus by m ensures each value is within the table
    unsigned int result = (a*x + b % p) % m;

    printf ("Hashed value of %c is %d\n",x,result);

    return 0;
}

