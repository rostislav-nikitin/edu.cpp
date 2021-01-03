// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <vector>
#include <mutex>

using namespace std;

template<typename T>
	class Data
	{
		T data;
	public:
		Data(const T &data):data{data}
		{
		}
		string get_type_name()
		{
			return typeid(data).name(); 
		}
	};

Data(const char *) -> Data<std::string>;
Data(int) -> Data<long long int>;

int main()
{
	//before CTAD
	pair<int, int> p1{1, 2};
	Data<int> d1 {1};

	//CTAD
	pair p2{1, 2};
	vector p3{2, 5};

	mutex m;
	lock_guard gl {m};

	cout << "Results: " << endl;
	Data d2{2};
	cout << d2.get_type_name() << endl;

	Data d3 {"Hello world"};
	cout << d3.get_type_name() << endl;

	return 0;
}
