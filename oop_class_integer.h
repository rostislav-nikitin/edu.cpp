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
		Integer(Integer &&obj);
		int get_value() const;
		void set_value(int value);
		~Integer();
};

