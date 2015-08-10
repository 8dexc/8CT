#ifndef STREAM_CIPHER_H
#define STREAM_CIPHER_H

#include <string>
#include <stdint.h>
#include "Cipher.h"

/******************************************************************************************************
*                                                                                                     *
*   Implementing new usable stream cipher:                                                            *
*   = initialize() must take key as string and completely prepare cipher for byte generation          *
*   = get_byte() must generate next byte in stream and completely prepare for next get_byte() call    *
*   = stream is reset when (and only when) initialize() is called with a new key string               *
*     (dont forget to add new stream cipher to Stream_Cipher enum and Cipher namespace in Cipher.h)   *
*                                                                                                     *
******************************************************************************************************/

class Stream_Cipher: public Cipher_t
{
protected:
    typedef uint8_t byte;
public:
    virtual void initialize (std::string key) { };
    virtual byte get_byte   () { return 0; };
};

#endif
