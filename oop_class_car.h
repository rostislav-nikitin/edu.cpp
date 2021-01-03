// Single-line comment
/*
 * Multiple line comment
 */
#pragma once
class Car
{
	private:
		float fuel{0};
		float speed{0};
		int passengers{0};
		int arr[3]{1, 2, 3};
		char *ptr{};
		static int total_count;
	public:
		Car();
		Car(float amount);
		Car(float fuelt, int passengers);
		~Car();
		void fill_fuel(float amount);
		void accelerate();
		void breake();
		void add_passengers(int passengers);
		void dashboard() const;
		static void show_count();

};

