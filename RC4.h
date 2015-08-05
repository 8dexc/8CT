#ifndef RC4_H
#define RC4_H

#include <string>
#include <stdint.h>
#include "PRNG.h"

class RC4: public PRNG
{
private:
    unsigned int i;
    unsigned int j;
    unsigned int k;
    byte S[0x100];
    byte seed[];

public:
                 RC4        ();
    virtual void initialize (std::string key);
    virtual byte get_byte   ();
}; 

#endif
