// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <vector>
#include <list>

// 1
const char * get_error_message(int error_no)
{
	return "Empty";
}

void show_error(const char *(*pfn)(int))
{
	
}
// 2 typedef
typedef const char *(*PFN)(int);

void show_error_typedef(PFN pfn)
{
	
}

// 3. type alias
using APFN = const char *(*)(int);

void show_error_type_alias(APFN pfn)
{

}

// 4. alias for templates 

template<typename T>
	using Names = std::vector<std::list<T>>;

using namespace std;

int main()
{
	return 0;
}
