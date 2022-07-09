#include <iostream>

using namespace std;

class Point
{
	private:
		int _x;
		int _y;

	public:
		Point(int x, int y) : _x{x}, _y{y}
		{
			cout << __PRETTY_FUNCTION__ << "x=" << _x << "; y=" << _y << endl;
		}

};

class Line
{
	private:
		Point _p1;
		Point _p2;
	public:
		Line(Point p1, Point p2) : _p1{p1}, _p2{p2}
		{
			cout << __PRETTY_FUNCTION__ << endl;
		}

		void print()
		{
			cout << "Line printed" << endl;
		}
};

template<typename ... Args>
	Line create_horizontal_line(int y, Args ... args)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		return  Line { Point{args, y} ... };
//		(args.print(), ...);
	}

int main()
{
	Line l1 = create_horizontal_line(0, 20, 50);

	return 0;
}
