#include <iostream>
#include "registeraddresses.hpp"
#include "bitFunctions.hpp"
int main() {
    short int registers[8];
    short int mem[65536];
    registers[PROGRAM_COUNTER] = mem[0];
    //sets the program to the start of memory

    //sets the power pin to on
    registers[POWERPIN] = 1;

    while(registers[POWERPIN])
    {

        ++registers[PROGRAM_COUNTER];

        registers[POWERPIN] = 0;
    }
    //test bitmask code
    short int i = 0xffff;

    //01010101 01010101
    short int j = bitFunctions::makeBits("0101000000000000");
    short int p = bitFunctions::makeBits("0111101101011101");

    bitFunctions::printBits(i);
    bitFunctions::printBits(j);
    bitFunctions::printBits(p);
    auto t = bitFunctions::mask(j,12,16);
    auto b = bitFunctions::mask(i,0,3);
    bitFunctions::printBits(t);
    bitFunctions::printBits(b);


    return 0;
}
