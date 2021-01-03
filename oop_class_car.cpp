// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "oop_class_car.h"

using namespace std;


int Car::total_count {0};

Car::Car():Car(0)
{
	cout << "Car()" << endl;
}

Car::Car(float amount):Car(amount, 0)
{
	cout << "Car(float)" << endl;
}

Car::Car(float fuel, int passengers)
{
	cout << "Car(float, int)" << endl;
	total_count++;

	this->fuel = fuel;
	this->passengers = passengers;
	this->speed = 0;
	
}

Car::~Car()
{
	cout << "~Car()" << endl;
	total_count--;
}

void Car::fill_fuel(float amount)
{
	fuel = amount;
}

void Car::accelerate()
{
	speed++;
	fuel -= 0.5f;
}

void Car::breake()
{
	speed = 0;
}

void foo(const Car &car)
{
}

void Car::add_passengers(int passengers)
{
	this->passengers = passengers;
	foo(*this);
}

void Car::show_count()
{
	cout << "Total cars: " << total_count << endl;
}

void Car::dashboard() const
{
	cout << "Fuel: " << fuel << endl;
	cout << "Speed: " << speed << endl;
	cout << "Passengers: " << passengers << endl;
	cout << "Array[2]: " << arr[2] << endl;
	cout << "Total count: " << total_count << endl;
}
