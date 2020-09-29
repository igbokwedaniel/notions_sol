
#include<cmath>
#include<iostream>

#include "proth_primality_checker.h"
#include "random_generator.h"


template<>
proth_type proth_prime_checker<proth_rand_generator>::run()
{
    proth_num.prepare();

    if(!proth_num.is_proth)
        return proth_type::COMPOSITE;

    long long max_val{proth_num.N-1};
    random_gen.max_val = max_val;
    random_gen.prepare();

    long long sample_size{powa(std::log2(proth_num.N),2)*proth_num.t};  
    long long start{0}, 
                a{0}, 
                b{0},
                b_2{0}, 
                exponent{(proth_num.N-1)/2};

    while (start <= sample_size){
        a       = random_gen.get_next_rand();
        b       = modular_exp(a,exponent,proth_num.N) - proth_num.N;
    
        std::cout<<  "a,b => " << a << " " << b  << std::endl;


        if(b == -1)
            return proth_type::PRIME;

        b_2  = modular_exp(b,2,proth_num.N);

        //std::cout<<  "a,b_2 => " << a << " " << b_2  << std::endl;

        //Lemma: Fermat's little theorem
        //if(b_2 != 1)
            //return proth_type::COMPOSITE;

        if(b_2 == 1 && b+proth_num.N !=1)
            return proth_type::COMPOSITE;
        
        ++start;
    }

    return proth_type::COMPOSITE;
}


/**
 * Bit implementations of modular exponentiation arithmetic
 *  Unsigned Long Long used to guarantee underflow 
 **/
long long modular_exp(ULL base, ULL exp, ULL mod) {
   ULL res = 1;
   while (exp > 0) {
      if (exp % 2 == 1)
         res= (res * base) % mod;
      exp = exp >> 1;
      base = (base * base) % mod;
   }
    return static_cast<long long> (res); //explicit cast to signed long long
}