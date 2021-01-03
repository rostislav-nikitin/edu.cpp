// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>
//#include <execution>

using namespace std;

class Timer
{
	std::chrono::steady_clock::time_point start_time;
	std::chrono::steady_clock::time_point end_time;
	//std::chrono::time_point end_time;
public:
	Timer()
	{
		start_time = std::chrono::steady_clock::now();
	}
	long stop()
	{
		end_time = std::chrono::steady_clock::now();
		auto difference = end_time - start_time;
		return std::chrono::duration_cast<std::chrono::milliseconds>(difference).count();
	}
};

constexpr unsigned VEC_SIZE {1000000};
std::vector<long> create_vector()
{
	std::vector<long> vec;
	vec.reserve(VEC_SIZE);
	std::default_random_engine engine {std::random_device{}()};
	std::uniform_int_distribution<long> dist {0, VEC_SIZE};
	for(unsigned i = 0; i < VEC_SIZE; ++i)
	{
		vec.push_back(dist(engine));
	}

	return vec;
}

int main()
{
	auto ds = create_vector();

	Timer timer;

	//std::sort(ds.begin(), ds.end());
	//std::sort(std::execution::seq, ds.begin(), ds.end());
	
	//auto result = std::accumulate(ds.begin(), ds.end(), 0L);
	//auto result = std::reduce(ds.begin(), ds.end(), 0L);

	cout << timer.stop() << endl;

	return 0;
}
