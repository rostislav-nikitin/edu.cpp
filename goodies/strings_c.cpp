// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <cstring>

using namespace std;

const char * combine(const char *p_first, const char *p_last)
{
	char * result = new char[strlen(p_first) + strlen(p_last) + 1];
	strcpy(result, p_first);
	strcat(result, p_last);

	return result;
}

int main()
{
	char first[10];
	char last[10];

	cin.getline(first, 10);
	cin.getline(last, 10);

	const char *full = combine(first, last);

	cout << "Full name is: " << full << endl;

	delete[] full;

	return 0;
}
