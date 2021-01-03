// Single-line comment
/*
 * Multiple line comment
 */

class Integer
{
	private:
		int *ptr_value {};

	public:
		Integer();
		Integer(int value);
		Integer(Integer const &obj);
		Integer(Integer &&obj) noexcept;
		int get_value() const;
		void set_value(int value);
		~Integer();

		Integer operator+(Integer const &a) const;
		Integer & operator++();
		Integer operator++ (int);
		bool operator == (Integer const &j) const;
		Integer & operator =(Integer const &a);
		Integer & operator =(Integer &&a);
		void operator ()() const;
		// use explicit keyword to accept onlt explicit type conversion: 
		// int x = static_cast<int>(Integer{44};
		// Otherwise implicit will be acceptable:
		// int x = Integer{33};
		explicit operator int();

		friend std::istream & operator >> (std::istream &in_stream, Integer &a);

		friend class Printer;
};

Integer operator + (int, Integer &);


class Printer
{
};
