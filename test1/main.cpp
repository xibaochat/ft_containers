#include "test.hpp"

struct timespec start;

void get_time_distance()
{
	struct timespec stop;
	clock_gettime(CLOCK_MONOTONIC, &stop);
	double time_distance;
	time_distance =  (stop.tv_sec - start.tv_sec  + stop.tv_nsec - start.tv_nsec) * 1e-9;
	std::cout << RED << "TIME <<< " << NC <<  std::fixed << time_distance << std::endl;
	clock_gettime(CLOCK_MONOTONIC, &start);
}

int main()
{
	clock_gettime(CLOCK_MONOTONIC, &start);
	test_vector();
	test_map();
	test_stack();
	test_set();
	test_42();

}
