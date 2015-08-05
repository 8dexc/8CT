#include "RC4.h"
#include <iostream>
#include <iomanip>

int main()
{
    RC4 rc4;
    PRNG *prng = &rc4;
    prng->initialize("Key");
    for(int x = 0; x < 10; x++)
        std::cout << std::hex << (int) prng->get_byte() << " ";
    std::cout << std::endl;

    prng->initialize("Key");
    for(int x = 0; x < 15; x++)
        std::cout << std::hex << (int) prng->get_byte() << " ";
    std::cout << std::endl;
    return 0;
}
