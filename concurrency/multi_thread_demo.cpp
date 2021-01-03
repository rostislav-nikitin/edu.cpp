// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <list>
#include <thread>

using namespace std;

const int DATA_SIZE = 100000000;
list<int> data {};

void _download()
{

	cout << "[Downloader] Download started" << endl;
	for(int i = 0; i < DATA_SIZE; ++i)
		data.push_back(i);
	cout << "[Downloader] Download finished" << endl;
}

int main()
{
	cout << "Download data" << endl;
	std::thread downloadThread {_download};
	//downloadThread.detach();
	cout << "Next operation..." << endl;

	if(downloadThread.joinable())
	{
		downloadThread.join();
	}
	system("Pause");

	return 0;
}
