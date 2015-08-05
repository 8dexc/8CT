#ifndef STREAM_CIPHER_H
#define STREAM_CIPHER_H
#include <string>
#include <iostream>
#include <fstream>
#include "RC4.h"

enum Result
{
    RESULT_SUCCESS,           // 0 = File was encrypted/decrypted successfully
    RESULT_DESTINATION_ERROR, // 1 = Default output file already exists
    RESULT_READ_ERROR,        // 2 = Invalid or nonexistant filepath
    RESULT_MISSING_HEADER     // 3 = File being decrypted lacks correct header format
};

enum Direction
{
    DIRECTION_ENCRYPT,
    DIRECTION_DECRYPT
};

enum Algorithm
{
    ALGORITHM_RC4
};


namespace crypt
{

    Direction direction     // Direction of function (Encrypt or Decrypt)
        = DIRECTION_ENCRYPT;

    RC4 rc4;                // Objects of selectable PRNGs

    PRNG *prng;             // Points to PRNG derived object (used for all interactions with selected PRNG)

    bool overwrite = false; // User-given permission to overwrite existing file in output path

    std::string password;   // User input password that is used to seed PRNG

    std::ifstream infile;   // File I/O streams
    std::ofstream outfile;
    
    // Internally Accessed Functions
    

    // Externally Accessed Functions
    Result load_file     (std::string filepath);
    Result set_out_file  (std::string filepath);
    void   set_direction (Direction d);
    void   set_passwd    (std::string password);
    Result encrypt       ();
}
#endif
