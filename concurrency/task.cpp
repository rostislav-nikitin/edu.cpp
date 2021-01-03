// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <future>

using namespace std;

int process(int count)
{
	int result {};

	for(int i = 0; i < count; ++i)
	{
		result += i;
		this_thread::sleep_for(chrono::milliseconds(300));
		cout << ".";
		cout.flush();
	}
	cout << endl;

	return result;
}

using namespace std::chrono_literals;

int main()
{
	// std::launch::defferred -- call func at *.wai() or *.get()
	// std::launch::async -- call func asynchronously
	future<int> sum = async(std::launch::async, process, 10);
	std::this_thread::sleep_for(1s);
	cout << "Next instruction exectuted." << endl;
	if(sum.valid())
	{
		// wait until shared state will be ready
		sum.wait();
		// wait until shared state will be ready and get shared state
		int sum_value = sum.get();
		cout << "sum=" << sum_value << endl;
	}

	return 0;
}
