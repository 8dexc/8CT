#ifndef PRNG_H
#define PRNG_H
#include <string>
#include <stdint.h>

/****************************************************************************************************
*                                                                                                   *
*   Implementing new usable PRNG:                                                                   *
*   = initialize() must take key as string and completely prepare PRNG for byte generation          *
*   = get_byte() must generate next byte in stream and completely prepare for next get_byte() call  *
*   = stream is reset when (and only when) initialize() is called with a new key string             *
*     (dont forget to add new PRNG to Algorithm enum and crypt namespace in Encryption.h)           *
*                                                                                                   *
****************************************************************************************************/

class PRNG
{
protected:
    typedef uint8_t byte;
public:
    virtual void initialize (std::string key) { };
    virtual byte get_byte   () { return 0; };
};

#endif
