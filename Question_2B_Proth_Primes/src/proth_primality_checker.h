#include "proth_number.h"
#include "random_generator.h"
#include<type_traits>
#include <cmath>

#ifndef _PROTH_PRIMALITY_CHECKER
#define _PROTH_PRIMALITY_CHECKER


typedef unsigned long long ULL;

template<typename G>
class proth_prime_checker
{

    static_assert(std::is_base_of<rand_generator, G>::value, "G must inherit from rand generator");

    public:
        G random_gen;
        proth_number proth_num;

        proth_prime_checker(G rand_gen, proth_number proth): random_gen{rand_gen}, proth_num{proth} {}
        proth_type run();
        long long powa(long long number, long long exponent){return std::pow(number, exponent);}
        long long powa_modulo(long long number, long long exponent, long long modulus){return powa(number, exponent) % modulus;}
       

};

long long modular_exp(ULL base, ULL exp, ULL mod);


#endif