// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <list>

using namespace std;

void _download()
{
	const int DATA_SIZE = 500000000;
	list<int> data;

	cout << "[Downloader] Download started" << endl;
	for(int i = 0; i < DATA_SIZE; ++i)
		data.push_back(i);
	cout << "[Downloader] Download finished" << endl;
}

int main()
{
	cout << "Download data" << endl;
	_download();
	cout << "Next operation..." << endl;

	return 0;
}
