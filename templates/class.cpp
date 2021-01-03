// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

template<typename T, int size>
	class Stack
	{
		int const Top_Default = -1;

		T buffer[size];
		int current {Top_Default};

	public:
		Stack() = default;
		Stack(Stack const &st);
/*		Stack(Stack const &st)
		{
			for(int i = 0; i < st.current + 1; i++)
			{
				buffer[i] = st.buffer[i];
			}
			current = st.current;
		}
*/
		void push(T const &item)
		{
			buffer[++current] = item;
		}

		T& pop()
		{
			return buffer[current--];
		}

		T& top()
		{
			return buffer[current];
		}

		bool is_empty()
		{
			return current == Top_Default;
		}

		static Stack Create();
	};

	template<typename T, int size>
		Stack<T, size> Stack<T, size>::Create()
		{
			return Stack<T, size>();
		}

	template<typename T, int size>
		Stack<T, size>::Stack(Stack<T, size> const &st)
		{
			for(int i = 0; i < st.current + 1; i++)
			{
				buffer[i] = st.buffer[i];
			}
			current = st.current;
		}

int main()
{

	Stack<int, 10> st = Stack<int, 10>::Create();
	st.push(10);
	st.push(-5);
	st.push(8);
	st.push(1);

	auto st2{st};

	while(!st2.is_empty())
	{
		cout << st2.pop() << " ";
	}

	cout << endl;

	return 0;
}
