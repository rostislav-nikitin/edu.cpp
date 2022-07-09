#include <iostream>
#include <type_traits>

using namespace std;

class A
{
	public:
		A(){ cout << "A()" << endl;}
		A(A const &a){ cout << "A(A const &)" << endl;}
		A(A&& a){ cout << "A(A &&)" << endl;}
		A& operator=(A const  &x)
		{
			cout << "=(A const &)" << endl;
			return *this;
		}
		A& operator=(A &&x)
		{
			cout << "=(A &&)" << endl;
			return *this;
		}
		friend ostream& operator << (ostream &out, A const &value);

};

class B
{
		public:
			A a;
			B() : a{}
			{
			}
			
};

ostream& operator << (ostream& out, A const &value)
{
		out << "A printed";

		return out;
}


template<class T> struct remove_references { typedef T type; };
template<class T> struct remove_references<T&> { typedef T type; };
template<class T> struct remove_references<T&&> { typedef T type; };

template<class T>
	T&& move_unsafe(T&& value)
	{
			cout << __PRETTY_FUNCTION__ << endl;
	//		cout << "unsafe :: T& " << value << endl;
			return static_cast<T&&>(value);
	}

template<class T>
	typename remove_references<T>::type&& move_safe(T&& value)
//	T&& move_safe(T&& value)
	{
//		if(!is_rvalue_reference<T>::value)
//			cout << "Error";
		
		cout << __PRETTY_FUNCTION__ << endl;
//		icout << "safe :: T&" << value << endl;
//
		return static_cast<typename remove_references<T>::type&&>(value);
//		typename remove_references<T>::type result = static_cast<typename remove_references<T>::type&&>(value);
//		auto result = static_cast<typename remove_references<T>::type&&>(value);
//		cout << typeid(result).name() << endl;

//		return sresult;
	}

template <typename T>
	T const & back(T const & x)
	{
			cout << x << endl;
			return x;
	}
template<class T>
	//T&& forward_safe(typename remove_references<T>::type& x)
	//T&& forward_safe(typename remove_references<T>::type& x)
	T&& forward_safe(T& x)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		return static_cast<T&&>(x);
	}

B create_B()
{
		return B{};
}

template<typename T, typename Args>
	T& create_safe(Args&& args)
	{
			cout << __PRETTY_FUNCTION__ << endl;
			return *new T{forward_safe<Args>(args)};
	}

int main()
{
	cout << "Crate B, and A inside B" << endl;
	B b{};
	cout << endl << endl;

	cout << "Unsafe :: Accept moving lvalues -> move constructor can be called for the lvalue -> can breake lvalue" << endl;
	A y{move_unsafe(b.a)};
	cout << endl << endl;

	cout << "Safe :: Accept moving only rvalues otherwise compilation error" << endl;
	A z1{move_safe(b.a)};
	cout << endl << endl;
	
	A z2{move_safe(B{}.a)};
	cout << endl << endl;


	cout << "Pefect forwarding" << endl;
	create_safe<A>(z1);
	create_safe<A>(A{});


	return 0;
}
