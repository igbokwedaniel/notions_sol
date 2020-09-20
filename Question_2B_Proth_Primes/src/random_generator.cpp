#include<random>
#include "random_generator.h"

void proth_rand_generator::prepare(){
    
    std::default_random_engine rd;
    std::random_device random_device;

    random_num_engine   = std::mt19937_64(rd());
    distribution        = std::uniform_int_distribution<std::mt19937_64::result_type>(min_val, max_val);

}

long long proth_rand_generator::get_next_rand(){
    return distribution(random_num_engine);
}