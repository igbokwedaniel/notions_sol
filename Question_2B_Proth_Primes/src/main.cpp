#include <iostream>

#include "random_generator.h"
#include "proth_number.h"
#include "proth_primality_checker.h"

int main(int argc, char *argv[])
{


	proth_rand_generator prand_generator{1};
	proth_number N{17};
	proth_prime_checker<proth_rand_generator> prime_checker{prand_generator,N};
	

	std::cout << prime_checker.run();
}