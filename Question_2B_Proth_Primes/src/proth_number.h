#include<cmath>
#include<iostream>

#ifndef _PROTH_NUMBER
#define _PROTH_NUMBER

enum class proth_type { COMPOSITE, PRIME};

/**
 * Proth Umbers have the form N = 2e^t + 1
 * and proth number posessing primality according to the proth theorem
 *  a^[(N-1)/2] == -1 (mod N)
 *  
 *  and b = a^[(N-1)/2] (mod N)
 * 
 **/
class proth_number{
    public:
        long long N{0};
        long long e{0};
        long long t{0};
        long long a{0};
        long long b{0};
        bool is_proth{false};

        proth_number(long long n) : N{n} {}
        void prepare();
        bool is_proth_number(){return is_proth;}
};

std::ostream& operator<<(std::ostream &strm, const proth_type &p);

std::ostream& operator<<(std::ostream &strm, const proth_number &p);

#endif