// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
	class PrettyPrinter
	{
		T *data;
	public:
		PrettyPrinter(T *data) : data{data}
		{
		}

		void print()
		{
			cout << "{" << *data << "}" << endl;
		}

		T get_data()
		{
			return *data;
		}
	};

template<>
	class PrettyPrinter<char *>
	{
		char * data;
	public:
		PrettyPrinter(char *data) : data{data}
		{
		}

		void print()
		{
			cout << "{" << data << "}" << endl;
		}

		char * get_data()
		{
			return data;
		}
	};


template<>
	void PrettyPrinter<std::vector<int>>::print()
	{
		cout << "{";
		for(auto item : *data)
		{
			cout << item << " ";
		}
		cout << "}" << endl;
	};

/*template<>
	class PrettyPrinter<vector<vector<int>>>
	{
		vector<vector<int>> *data;
	public:
		PrettyPrinter(vector<vector<int>> *data) : data{data}
		{
		}

		void print()
		{
			cout << "{" ;
			for(vector<int> outer : *data)
			{
				cout << "{";
				for(int inner : outer)
				{
					cout << inner << " ";
				}
				cout << "}" << endl;
			}
			cout << "}" << endl;

		}

		std::vector<std::vector<int>> get_data()
		{
			return *data;
		}
	};
*/

template<>
	void PrettyPrinter<vector<vector<int>>>::print()
	{
		cout << "{" ;
		for(vector<int> outer : *data)
		{
			cout << "{";
			for(int inner : outer)
			{
				cout << inner << " ";
			}
			cout << "}" << endl;
		}
		cout << "}" << endl;
	}

int main()
{
	float f = 5.14;
	PrettyPrinter<float> p{&f};
	p.print();
	cout << p.get_data() << endl;

	char *str = {"Hello world!"};
	PrettyPrinter<char *> pc {str};
	pc.print();
	cout << pc.get_data() << endl;

	std::vector<int> v{1, 2, 3, 4};
	PrettyPrinter<std::vector<int>>pv {&v};
	pv.print();

	vector<vector<int>> vvi {{1, 2, 3}, {9, 5, 1}};
	PrettyPrinter<vector<vector<int>>> pvvi {&vvi};
	pvvi.print();
	
	
	return 0;
}
