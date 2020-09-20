#include<cmath>
#include<random>


/**
 * Random Numbr generator base class with default
 * Mersene Twister Engine and Uniform Distribution  function
 **/
class rand_generator
{
    public:
        std::mt19937_64 random_num_engine;
        std::uniform_int_distribution<std::mt19937_64::result_type> distribution;
        long long max_val{1};
        long long min_val{1};
        virtual long long get_next_rand() = 0; 
        virtual void prepare() = 0; 
        virtual ˜rand_generator() {} // destructor (§3.2.1.2)
        
};


class proth_rand_generator : public rand_generator{
    public:
        long long max_val{1};
        proth_rand_generator(long long max) : max_val{max}{}
        void prepare();
        long long get_next_rand();

};