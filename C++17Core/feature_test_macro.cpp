// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <string>
#ifdef __has_include
#	if __has_include(<filesystem>)
#		include <filesystem>
		namespace fs = std::filesystem;
#	else
#		include <experimental/filesystem>
		namespace fs = std::experimental::filesystem;
#	endif
#endif

int main()
{
	fs::path p {R"(/usr/bin)"};


	return 0;
}
