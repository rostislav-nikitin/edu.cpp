// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex sync{};

void _process()
{
	std::lock_guard<mutex> lg {sync};
	cout << "this.id: \t" << std::this_thread::get_id() << endl;
}

int main()
{
	std::thread t1{_process};

	std::lock_guard<mutex> lg {sync};

	cout << "t1.id: \t\t" << t1.get_id() << endl;
	cout << "Cores: \t\t" << t1.hardware_concurrency() << endl;

	lg.~lock_guard();
	t1.join();

	return 0;
}
