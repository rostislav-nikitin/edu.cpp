// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "oop_class_car.h"

using namespace std;

int main()
{
	Car car_zero;

	Car::show_count();
	Car car(4);
	
	//car.fill_fuel(6);
	car.accelerate();
	car.accelerate();
	car.accelerate();
	car.accelerate();
	car.dashboard();

	// Read-only Car object
	Car const car_ro(5);
	// Call to accelerate cause compilation error (const object but accelerate is non-const)
	//car_ro.accelerate();
	car_ro.dashboard();
	Car::show_count();

	return 0;
}
