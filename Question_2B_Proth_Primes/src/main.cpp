#include <iostream>
#include "random_generator.h"
#include "proth_number.h"

int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;
	proth_rand_generator generator{1000};
	proth_number proth_num{17};
	proth_num.prepare();
	std::cout << generator.get_next_rand() << " "  << generator.get_next_rand() << " " << proth_num.e << "  " << generator.max_val;
}