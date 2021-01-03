// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;
/*
template<typename T, int size>
	class PrettyPrinter
	{
		T *data;
	public:
		PrettyPrinter(T *data) : data {data}
		{
			*data = 100;
		}

		void print()
		{
			cout << "Columns: " << size << endl;
			cout << *data << endl;
		}
	};

template<typename T>
	class PrettyPrinter<T, 80>
	{
		T *data;
	public:
		PrettyPrinter(T *data) : data{data}
		{
		}

		void print()
		{
			cout << "Columns [80]" << endl;
			cout << *data << endl;
		}
	};
*/

template<typename T>
	class SmartPointer
	{
		T *ptr;
		SmartPointer(T *ptr) : ptr{ptr}
		{
		}

		T * operator -> ()
		{
			return ptr;
		}

		T &  operator * ()
		{
			return *ptr;
		}

		~SmartPointer()
		{
			delete ptr;
		}

	};

template<typename T> 
	class SmartPointer<T[]>
	{
		T *arr;
	public:
		SmartPointer(T *arr) : arr{arr}
		{
		}
		
		T & operator [] (int index)
		{
			return arr[index];
		}

		~SmartPointer()
		{
			delete[] arr;
		}
	};


int main()
{
/*	int value = 50;
	PrettyPrinter<int, 40> pp{&value};
	pp.print();

	PrettyPrinter<int, 80> pp80{&value};
	pp80.print();
*/
//	int arr[3] {1, 2, 3};
	SmartPointer<int[]> sp {new int[3]{1, 2, 3}};

	for(int i = 0; i < 3; ++i)
	{
		auto item = sp[i];
		cout << item << endl;
	}


	return 0;
}
