#include <iostream>
#include <fstream>

#include "random_generator.h"
#include "proth_number.h"
#include "proth_primality_checker.h"

void test();

int main(int argc, char *argv[])
{
	test();	
}

void test(){

	proth_rand_generator prand_generator{1};
	proth_number N{1};
	proth_prime_checker<proth_rand_generator> prime_checker{prand_generator,N};
	
	int passed{0}, total{0};

	std::ifstream testFile ("test.txt");
	if (testFile.is_open())
	{
		long long N;
		int res;
		std::string mark{"FAILED"};

		while (testFile >> N && testFile >> res )
		{
			mark = "FAILED";
			++total;
			prime_checker.proth_num.N = N;
			proth_type p_res =  prime_checker.run() ;

			if(static_cast<int>(p_res) == res)
				{++passed; mark = "PASSED";}

			std::cout << total <<  ")\t" << N << "\t\t is " << p_res << "\t\t ==> " << mark << std::endl ;
		}
		testFile.close();

		std::cout << std::endl << "Total: " << total << " || passed: " << passed << " || failed: " << total-passed << std::endl;
	}
}