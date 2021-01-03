// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>

using namespace std;

class Distance
{
	long double kilometers;
	public:
		Distance(long double km) : kilometers{km}
		{
		}

		long double get_km() const
		{
			return kilometers;
		}

		void set_km(long double val)
		{
			kilometers = val;
		}
};

Distance operator"" _mi(long double val)
{
	return Distance{val * 1.6};
}

Distance operator"" _meters(long double val)
{
	return Distance{val / 1000};
}

int main()
{
	Distance dist {32.0_mi};
	Distance dist2 {100.0_meters};

	cout << "km = " << dist.get_km() << endl;
	cout << "km = " << dist2.get_km() << endl;

	return 0;
}
