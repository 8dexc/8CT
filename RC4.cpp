#include <algorithm>
#include <stdint.h>
#include "RC4.h"

typedef uint8_t byte;

RC4::RC4 () { }

void RC4::initialize (std::string key)
{
    byte seed[key.length()];                // Converts key string into byte[] for seeding
    for(unsigned int x = 0; x < key.length(); x++)
    {
        seed[x] = key.at(x);
    }

    for(i = 0x0; i < 0x100; i++)            // Loads all possible bytes into S[]
    {
        S[i] = i;
    }

    for(i = 0x0, j = 0x0; i < 0x100; i++)   // Creates initial permutation of S[] using seed
    {
        j = (j + S[i] + seed[i % sizeof(seed)]) % 0x100;
                
        S[i] = S[i] ^ S[j];         // Swaps the values of S[i] and S[j]
        S[j] = S[i] ^ S[j];
        S[i] = S[i] ^ S[j];
    }

    i = 0x0;
    j = 0x0;
}

byte RC4::get_byte ()                       // Advances permutation and returns pseudorandom byte
{
    i = (i + 0x1)  % 0x100;
    j = (j + S[i]) % 0x100;
    k = S[(S[i] + S[j]) % 0x100];
    return k;
}
 
