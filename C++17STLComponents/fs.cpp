// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <vector>
#include <filesystem>
#include <algorithm>


using namespace std;
namespace fs = std::filesystem;

void show_files()
{

	fs::path my {R"(/home/s0lid)"};

	for(const fs::directory_entry &de : fs::directory_iterator{my})
	{
		switch(const auto &p = de.path(); de.status().type())
		{
			case fs::file_type::directory:
				cout << "[DIR]\t\t" << p.string() << endl;
				break;
			case fs::file_type::regular:
				cout << de.file_size() << "\t\t" << p.string() << endl;
				break;
		}
		//cout << de << endl;
	}
}

string get_permissions(const fs::perms &p)
{
	ostringstream out;
	out << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-");
	out << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-");
	out << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-");
	out << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-");
	out << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-");
	out << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-");
	out << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-");
	out << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-");
	out << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-");

	return out.str();
}

void show_vector(std::vector<fs::directory_entry> partitioned)
{
	for(auto &de : partitioned)
	{
		switch(const auto &p = de.path(); fs::status(p).type())
		{
			case fs::file_type::directory:
				cout << "[DIR]\t\t" << p.string() << endl;
				break;
			case fs::file_type::regular:
				cout << get_permissions(fs::status(p).permissions()) << "\t" << de.file_size() << "\t\t" << p.string() << "\t" << endl;
				break;
		}
	}
}

std::vector<fs::directory_entry> get_files_partitioned(std::string_view path_to_show)
{
	std::vector<fs::directory_entry> result {};

	fs::path my {path_to_show};

	for(const fs::directory_entry &de : fs::directory_iterator{my})
	{
		result.push_back(de);	
	}

	std::partition(
		result.begin(), 
		result.end(), 
		[](const fs::directory_entry & de)
		{
			return de.is_directory();
		}
	);

	return result;
}

void show_files_partitioned(std::string_view path_to_show)
{
	show_vector(get_files_partitioned(path_to_show));
}

void manipulate_dirs(string_view path_to_use)
{
	fs::path pth{path_to_use};

	if(!fs::exists(pth))
		cout << "Path not exists." << endl;
	else
	{
		pth /= "NewDir";

		if(fs::create_directory(pth))
		{
			cout << "Directory created" << endl;
		}
		else
		{
			cout << "Could not create directory" << endl;
		}
	

	//pth /= "NewDir";

		if(fs::exists(pth))
		{
			if(fs::remove(pth))
			{
				cout << "Directory removed" << endl;
			}
			else
			{
				cout << "Could not remove directory" << endl;
			}
		}

		cout << fs::current_path() << endl;
		try
		{
			cout << "Changing path" << endl;
			fs::current_path(pth);
		}
		catch(std::exception &ex)
		{
			cout << ex.what() << endl;
		}

		std::error_code err_code;
		fs::current_path(pth, err_code);
		if(err_code)
		{
			cout << err_code.message() << endl;
		}
	}


		
}

void set_permissions(string_view p)
{
	fs::path pth{p};
	pth /= "file";
	fs::permissions(pth, fs::perms::owner_exec, fs::perm_options::add);
}


int main()
{
	string_view work_path = R"(/home/s0lid/temp)";
	//manipulate_dirs(work_path);
	show_files_partitioned(work_path);
	set_permissions(work_path);
	
	
	return 0;
}
