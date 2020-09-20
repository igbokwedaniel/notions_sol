
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

    long long max_val{proth_num.N*3};
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
        b       = powa_modulo(a,exponent,proth_num.N) - proth_num.N;
    
        std::cout<<  "a,b => " << a << " " << b  << std::endl;


        if(b == -1)
            return proth_type::PRIME;

        b_2 = powa_modulo(b,2,proth_num.N);

        std::cout<<  "b^2 mod N => " << b_2 << std::endl;

        if(b_2 != 1)
            return proth_type::COMPOSITE;
        
        if(b == 1 and b_2 == 1)
            return proth_type::COMPOSITE;

        

        ++start;
    }

    return proth_type::COMPOSITE;
}