// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <list>
#include <thread>

using namespace std;

class String
{
public:
	String()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	String(const String &)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	String & operator=(const String &)
	{
		cout << "operator" << __PRETTY_FUNCTION__ << endl;
		return *this;
	}
	~String()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

const int DATA_SIZE = 1000000;
list<int> data {};

void _download(const String &filename)
{
	//cout << "Filename: " << filename << endl;
	cout << "[Downloader] Download started" << endl;
	for(int i = 0; i < DATA_SIZE; ++i)
		data.push_back(i);
	cout << "[Downloader] Download finished" << endl;
}

int main()
{
	//string filename = "http://downloads.google.com/file1.txt";
	const String filename;
	cout << "Download data" << endl;
	std::thread downloadThread {_download, std::cref(filename)};
	//downloadThread.detach();
	cout << "Next operation..." << endl;

	if(downloadThread.joinable())
	{
		downloadThread.join();
	}

	return 0;
}
