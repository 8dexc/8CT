#include <sys/stat.h>
#include"Cipher.h"

/********************************
*                               *
* Internally Accessed Functions *
*                               *
********************************/

bool exists (const std::string& name)   // Checks if a file exists at the given path
{                                       // << Stolen from http://stackoverflow.com/questions/12774207 >>
    struct stat buffer;   
    return (stat (name.c_str(), &buffer) == 0); 
}

/********************************
*                               *
* Externally Accessed Functions *
*                               *
********************************/

void set_algorithm (Algorithm a)        // Sets prng to the address of the object of the specified algorithm
{
    using namespace Cipher;
    switch(a)
    {
        case ALGORITHM_RC4:
            prng = &rc4;
            break;
    }
}

Result inject_header ()                 // Encrypts header meta-data to output file
{
    return RESULT_SUCCESS;
}

Result extract_header ()                // Decrypt file header and apply meta-data info
{
    return RESULT_SUCCESS;
}

Result set_in_file (const char *path)   // If specified file does not exist, return error 2
{                                       // Else open file into file input stream
    using namespace Cipher;
    if(!exists(path))
    {
        return RESULT_READ_ERROR;
    }
    infile.open(path, std::ios::binary);
    return RESULT_SUCCESS;
}

Result set_out_file (const char *path)  // If specified file already exists and overwriting is disabled, return error 1
{                                       // Else open file into file output stream
    using namespace Cipher;
    if(exists(path) && !overwrite)
    {
        return RESULT_DESTINATION_ERROR;
    }
    outfile.open(path, std::ios::binary);
    return RESULT_SUCCESS;
}

void set_direction (Direction dir)      // Sets whether the program will be encrypting a file or decrypting a 0ef
{
    Cipher::direction = dir;
}

void set_passwd (std::string pass)      // Sets password that is used to seed PRNG
{
    Cipher::password = pass;
}

Result encrypt ()                       // Performs XOR on byte read from file and corresponding pseudorandom byte
{                                       // Directly writes result to output file until EOF
    using namespace Cipher;
    switch(direction)
    {
    case DIRECTION_ENCRYPT:
        inject_header();
        break;
    case DIRECTION_DECRYPT:
        extract_header();
        break;    
    }
    
    while(infile)
    {
        uint8_t kb, ptb, ctb;           // Generates ciphertext byte (ctb) from XOR of plaintext byte (ptb) and key byte (kb)
        ctb = ptb ^ kb;
        outfile << ctb;
    }
    return RESULT_SUCCESS;
}
