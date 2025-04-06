#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;

int last_digit_func(int base, int power)
{
	int base_last_digit = base % 10;
	int result = 1;

	for (int i = 0; i < power; i++)
	{
		result = (result * base_last_digit) % 10;
	}

	return result;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int number, power1, power2;
	
	cout << "Введите число: ";
	cin >> number;

	cout << "Введите первую степень: ";
	cin >> power1;

	cout << "Введите вторую степень: ";
	cin >> power2;

	int first_power = last_digit_func(number, power1);
	int last_digit = last_digit_func(first_power, power2);

	cout << "Последняя цифра трехэтажного числа:  " << last_digit;
}