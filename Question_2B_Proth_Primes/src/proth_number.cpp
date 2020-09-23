#include<cmath>
#include<iostream>
#include<string>

#include "proth_number.h"
bool isPowerOfTwo(int n);
int getPowerOfTwo(int n);

// Number must take the form N = [2^(t)]*t + 1 where t is an odd number 1,3,5.... 2m+1
void proth_number::prepare(){
    is_proth = false;
    long long  n{N-1};
    int t{1};
    
     while (t < (n / t)) { 
        if (n % t == 0 && isPowerOfTwo(n / t)) { 
            this->t     = t;
            this->e     = getPowerOfTwo(n / t);
            is_proth    = true;
        } 
        t += 2; 
    } 

}



bool isPowerOfTwo(int n) 
{ 
    return (n && !(n & (n - 1))); 
} 

int getPowerOfTwo(int n){
    int bitCount{0};

    while(n >= 1)
    {
        bitCount += 1;
        n = n >> 1;
    }
    return bitCount-1;
}

std::ostream& operator<<(std::ostream &strm, const proth_type &p) {

    std::string result{""};
    switch(p){
        case proth_type::COMPOSITE:
            result = "COMPOSITE ";
            break;

        case proth_type::PRIME:
            result = "PRIME ";
            break;
    }
    return strm << result;
}

std::ostream& operator<<(std::ostream &strm, const proth_number &p) {
    return strm << "N => " << p.N << " = 2^[" << p.e << "]*" << p.t << " + 1 ";
}