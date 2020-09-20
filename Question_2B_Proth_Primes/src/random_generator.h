#include<cmath>
#include<random>


#ifndef _RANDOM_GENERATOR
#define _RANDOM_GENERATOR

/**
 * Random Numbr generator base class with default
 * Mersene Twister Engine and Uniform Distribution  function
 **/
class rand_generator
{
    public:
        long long max_val{1};
        long long min_val{1};

        rand_generator(){}
        virtual long long get_next_rand() = 0; 
        virtual void prepare() = 0; 
        virtual ~rand_generator() {} // destructor
    
    protected:
        std::mt19937_64 random_num_engine;
        std::uniform_int_distribution<std::mt19937_64::result_type> distribution;
        
};


class proth_rand_generator : public rand_generator{
    public:
        long long max_val{1};
        proth_rand_generator(long long max) : rand_generator(), max_val{max}{ }
        proth_rand_generator() : rand_generator(){}
        void prepare();
        long long get_next_rand();

};

#endif