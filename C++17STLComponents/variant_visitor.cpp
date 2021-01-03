// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <variant>

using namespace std;

struct Number
{
	int num;
	int get_num() const
	{
		//cout << num << endl;
		return num;
	}
	Number(int num) : num{num}
	{
		//cout << num << endl;
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Number() : num{0}
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	~Number()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Number(const Number& other)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Number(Number && other)
	{
		this->num = other.num;
		cout << __PRETTY_FUNCTION__ << endl;
	}

	Number& operator=(const Number &other)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		if(this == &other)
		{
			return *this;
		}

		this->num = other.num;
		return *this;
	}
	Number& operator=(Number &&other)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		if(this == &other)
		{
			return *this;
		}
		this->num = other.num;
		return *this;
		
	}
};

std::ostream &operator << (std::ostream &out, Number &n)
{
	out << n.get_num();

	return out;
}


struct Visitor
{
	void operator()(string s) const
	{
		cout << s << endl;
	}
	void operator()(int i) const
	{
		cout << i << endl;
	}
	void operator()(Number &n) const
	{
		cout << n << endl;
	}
};

struct Modifier
{
	void operator()(string &s) const
	{
		s += "[Modified]";
	}
	void operator()(int &i) const
	{
		i += 3;
	}
	void operator()(Number &n) const
	{
		n = 256;
	}
};

int main()
{
	// Visitor
	std::variant<std::string, int, Number> v{"Hi there!"};
	std::visit(Visitor{}, v);
	
	v = 10;
	std::visit(Visitor{}, v);

	v = Number{55};
	std::visit(Visitor{}, v);

	// Modifier
	// Change active member to string
	v = "Hi there!";
	std::visit(Modifier{}, v);
	std::visit(Visitor{}, v);

	// Change active member to int
	v = 20;
	std::visit(Modifier{}, v);
	std::visit(Visitor{}, v);

	// Change active member to Number
	v = Number{25};
	std::visit(Modifier{}, v);
	std::visit(Visitor{}, v);


	//Lambda as visitor
	v = 556;
	auto lambda = [](auto &x)
		{
			using T = std::decay_t<decltype(x)>;
			if constexpr(std::is_same_v<T, string>)
			{
				cout << "[Lambda]. string=" << x << endl;
			}
			else if constexpr(std::is_same_v<T, int>)
			{
				cout << "[Lambda]. int=" << x << endl;
			}
			else if constexpr(std::is_same_v<T, Number>)
			{
				cout << "[Lambda]. Number=" << x << endl;
			}
			else
			{
				cout << "[Lambda]. Not found" << endl;
			}

		};

	v = "Test";
	std::visit(lambda , v);

	v = 128;
	std::visit(lambda , v);

	v = Number {192};
	std::visit(lambda , v);

	return 0;
}
