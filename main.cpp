#include <iostream>
#include "registeraddresses.hpp"
#include "bitmasks.hpp"

//
void showbits(unsigned short int x)
{
    int i;
    for(i=(sizeof(short int)*8)-1; i>=0; i--)
        (x&(1u<<i))?putchar('1'):putchar('0');

    std::cout << std::endl;
}

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
    short int j = bitmask::makeBit("0101000000000000");
    short int p = bitmask::makeBit("0111101101011101");

    showbits(i);
    showbits(j);
    showbits(p);
    auto t = bitmask::mask(j,12,16);
    auto b = bitmask::mask(i,0,3);
    showbits(t);
    showbits(b);


    return 0;
}
