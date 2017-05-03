//
// Created by odin on 2017/05/03.
//

#ifndef OVM_BITMASKS_HPP
#define OVM_BITMASKS_HPP

#include <math.h>
#include <string>
namespace bitmask {
    short int mask(const short int value,char from, char to ) {
        const short int mask = pow(2,to-from)-1;
        return (value >> from) & mask;
    }
    short int makeBit(const std::string val)
    {
        unsigned short int ret;
        int l = val.length();
        for(int i = 0; i < l;++i)
            if(val.at((l-1)-i) == '1')
                ret += pow(2,i);
        return ret;
    }
}

#endif //OVM_BITMASKS_HPP
