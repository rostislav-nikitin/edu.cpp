// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <fstream>
#include <experimental/filesystem>

//#define debug

using namespace std;
using namespace std::experimental::filesystem;

void file_copy(path &source, path &destination);
void directory_copy(path &source, path &destination);

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		cout << "[ERROR] Invalid arguments.\nUsage:\n\tcopy {source path} {destination path}\n";
	}
	path source {argv[1]};
	path destination = {argv[2]};

#ifdef debug
	cout << source << endl;
	cout << destination << endl;
#endif

	//path fs {R"(/home/s0lid)"};
	if(is_regular_file(source) && !is_directory(destination))
	{
#if debug
		cout << "Copy file to file" << endl;
#endif
		file_copy(source, destination);
	}
	else if(is_regular_file(source) && is_directory(destination))
	{
#if debug
		cout << "Copy file to directory" << endl;
#endif
		path filename = source.filename();
		destination /= filename;
		file_copy(source, destination);
	}
	else if(is_directory(source) && is_directory(destination))
	{
#if debug
		cout << "Source & dest are dirs" << endl;
#endif
		directory_copy(source, destination);

	}

	return 0;
}


void file_copy(path &source, path &destination)
{
	cout << destination;
	cout.flush();
	constexpr int buffer_size = 1;
	char buffer[buffer_size];

	unsigned int bytes_copied {0};

	std::ifstream in {source, std::ios_base::binary | std::ios_base::in};

	std::ofstream out {destination, std::ios_base::binary | std::ios_base::out};

	uintmax_t size = file_size(source);
	uintmax_t ten_percent = size / 10;

	while(in.read(buffer, buffer_size))
	{
		if(!out.write(buffer, buffer_size))
		{
			cout << "Copy error" << endl;
			break;
		}
		++bytes_copied;
		if((bytes_copied % ten_percent) == 0)
		{
			cout << ".";
			cout.flush();
		}
	}
	in.close();
	out.close();
	cout << "Done" << endl;
	cout << "eof=" << in.eof() << " fail=" << in.fail() << " good=" << in.good() << endl;

	//cout << "Bytes copied: " << bytes_copied << endl;
}


void directory_copy(path &source, path &destination)
{
	for(auto &source_entry : directory_iterator{source})
	{
		if(is_regular_file(source_entry))
		{
			path source_filename = source_entry.path().filename();
			path destination_file = destination/source_filename;
			path source_file = source_entry.path();
			file_copy(source_file, destination_file);

		}
	}
}
