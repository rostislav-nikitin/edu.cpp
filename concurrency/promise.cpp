// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <future>

using namespace std;

int process(std::promise<int> & count)
{
	int result {};
	future<int> f_count = count.get_future();
	cout << "[Task] Waiting for a count." << endl;
	int count_value = f_count.get();
	cout << "[Task] Count ready." << endl;

	for(int i = 0; i < count_value; ++i)
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
	
	std::promise<int> prom {};
	future<int> sum = async(process, std::ref(prom));
	int sum_value {};
	std::this_thread::sleep_for(1s);
	cout << "Setting count" << endl;

	prom.set_value(15);

	cout << "Next instruction exectuted." << endl;
	if(sum.valid())
	{
		// wait until shared state will be ready
		auto ws = sum.wait_for(4s);
		switch(ws)
		{
			case std::future_status::deferred:
				cout << "Task is synchronous" << endl;
				break;
			case std::future_status::ready:
				cout << "Task is ready" << endl;
				sum_value = sum.get();
				cout << "sum=" << sum_value << endl;
				break;
			case std::future_status::timeout:
				cout << "Task is timed out" << endl;
					
				break;
		}
		// wait until shared state will be ready and get shared state
	}

	return 0;
}
