// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

const int DATA_SIZE = 10000;
list<int> data {};

mutex sync {};

void _download_one()
{
	cout << "[Downloader] Download started" << endl;
	for(int i = 0; i < DATA_SIZE; ++i)
	{
		sync.lock();
		data.push_back(i);
		sync.unlock();
	}
	cout << "[Downloader] Download finished" << endl;
}
void _download_two()
{
	cout << "[Downloader] Download started" << endl;
	for(int i = 0; i < DATA_SIZE; ++i)
	{
		sync.lock();
		data.push_back(i);
		sync.unlock();
	}
	cout << "[Downloader] Download finished" << endl;
}

int main()
{
	cout << "Download data" << endl;

	std::thread downloadThread_one {_download_one};
	std::thread downloadThread_two {_download_two};

	cout << "Next operation..." << endl;

	downloadThread_one.join();
	downloadThread_two.join();

	cout << data.size() << endl;

	return 0;
}
