// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

class Stream
{
		std::string filename;
	public:
		Stream(const std::string &filename):filename(filename)
		{
			cout << __PRETTY_FUNCTION__ << endl;
		}
		std::string get_filename() const
		{
			return filename;
		}
		virtual ~Stream()
		{
			cout << __PRETTY_FUNCTION__ << endl;
		}
};

class OutputStream : virtual public Stream
{
		std::ostream &out;
	public:
		OutputStream(const std::string &filename, std::ostream &o) : out(o), Stream(filename)
		{
			cout << __PRETTY_FUNCTION__ << endl;
		}

		std::ostream & operator << (const std::string &data)
		{
			out << data;
			return out;
		}
		~OutputStream()
		{
			cout << __PRETTY_FUNCTION__ << endl;
		}
}; 

class InputStream : virtual public Stream
{
		std::istream &in;
	public:
		InputStream(const std::string filename, std::istream&i) : in(i), Stream(filename)
		{
			cout << __PRETTY_FUNCTION__ << endl;
		}
		std::istream & operator >> (std::string &data)
		{
			in >> data;
			return in;
		}
		~InputStream()
		{
			cout << __PRETTY_FUNCTION__ << endl;
		}
};

class IOStream : public OutputStream, public InputStream
{
	public:
		IOStream(const std::string &filename) : OutputStream(filename, std::cout), InputStream(filename, std::cin), Stream(filename)
		{
			cout << __PRETTY_FUNCTION__ << endl;
		}
		~IOStream()
		{
			cout << __PRETTY_FUNCTION__ << endl;
		}
};

int main()
{
	IOStream *stream = new IOStream{"doc.txt"};
	std::string data;
	*stream >> data;
	*stream << data << endl;
	cout << "filename=" << stream->get_filename() << endl;
	InputStream *is = dynamic_cast<InputStream*>(stream);
	delete is;
	//delete stream;
	return 0;
}
