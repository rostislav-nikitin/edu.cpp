// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Record
{
	int id;
	char name[10];
};

void write_record(Record *p)
{
	std::ofstream out {"records", std::ios_base::binary | std::ios_base::out};
	out.write((char *)p, sizeof(Record)); 
	out.close();
}

Record read_record()
{
	Record result;
	std::ifstream in {"records", std::ios_base::binary | std::ios_base::in};
	in.read((char *)&result, sizeof(Record));
	in.close();

	return result;

}

int main()
{
	/*std::ofstream textstream {"data"};
	textstream << 12345678;

	std::ofstream binstream {"bin_data", std::ios::ios_base::binary | std::ios_base::out};
	int num {12345678};
	binstream.write((const char *)&num, sizeof(num));
	binstream.close();


	std::ifstream input {"bin_data", std::ios_base::binary| std::ios_base::in};
	int in_num {};
	//char in_str_num[sizeof(in_num)];
	input.read((char *)&in_num, sizeof(in_num));
	cout << in_num << endl;*/

	Record r {100, "John"};
	cout << "id=" << r.id << " name=" << r.name << endl;
	//r.id { 100 };
	//r.name { "John" } ;

	write_record (&r);
	r = read_record();
	cout << "id=" << r.id << " name=" << r.name << endl;

	return 0;
}
