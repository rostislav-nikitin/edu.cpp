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
	int sum_value {};

	std::this_thread::sleep_for(1s);
	cout << "Next instruction exectuted." << endl;
	if(sum.valid())
	{
		auto tp = std::chrono::system_clock::now();
		tp += 1s;
		//cout << typeid(tp).name() << endl;
		// wait until shared state will be ready
		auto ws = sum.wait_until(tp);
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
