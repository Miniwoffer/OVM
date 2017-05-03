//
// Created by odin on 2017/05/03.
//

#ifndef OVM_BITMASKS_HPP
#define OVM_BITMASKS_HPP

#include <math.h>
#include <string>
namespace bitFunctions {
    short int mask(const short int value,char from, char to ) {
        const short int mask = pow(2,to-from)-1;
        return (value >> from) & mask;
    }
    short int makeBits(const std::string val)
    {
        unsigned short int ret;
        int l = val.length();
        for(int i = 0; i < l;++i)
            if(val.at((l-1)-i) == '1')
                ret += pow(2,i);
        return ret;
    }
    void printBits(unsigned short int bits)
    {
        int i;
        for(i=(sizeof(short int)*8)-1; i>=0; --i)
            if(bits & (1u << i))
                std::cout << ('1');
            else
                std::cout << ('0');
        std::cout << std::endl;
    }
}

#endif //OVM_BITMASKS_HPP
