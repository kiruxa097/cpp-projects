/*
	Проект для тренировки навыков работы с функциями, локальными и глобальными переменными, прототипами функций, использованием функций в выражениях
*/



#include <iostream>
#include <cmath>
using namespace std;

// Глобальная переменная
double pi = 3.14;

// Прототипы функций для нахождения площадей
double circle_area(double r);  
double rectangle_area(double a, double b);
double triangle_area(double a, double b, double c);

// Основная функция
int main()
{
	int v;
	cout << "Enter:\n1 - circle area\n2 - rectangle area\n3 - triangle area\n0 - exit\n";
	cout << "Enter: ";
	cin >> v;
	while (v > 3 || v < 0)  // Проверка корректного ввода
	{
		cout << "Enter a number from the above list: ";
		cin >> v;
	}
	switch (v) {
		case 1:  // При выборе нахождения площади круга
		{
			double r;  // Локальная переменная
			cout << "Enter radius: ";
			cin >> r;
			cout << "S = " << circle_area(r);
			break;
		}
		case 2:  // При выборе нахождения площади прямоугольника 
		{
			double a, b;  // Локальные переменные
			cout << "Enter length: ";
			cin >> a;
			cout << "Enter width: ";
			cin >> b;
			cout << "S = " << rectangle_area(a, b);
			break;
		}
		case 3:  // При выборы нахождения площади треугольника 
		{
			double a, b, c;  // Локальные переменные
			cout << "Enter 1 side: ";
			cin >> a;
			cout << "Enter 2 side: ";
			cin >> b;
			cout << "Enter 3 side: ";
			cin >> c;
			if (a + b > c && b + c > a && a + c > b) cout << "S = " << triangle_area(a, b, c);  // Проверка на существование треугольника
			else cout << "There is no such triangle.";
			break;
		}
		case 0:
		{
			cout << "The program has finished its execution.";
			break;
		}
	}
	return 0;
}

// Функция для расчета площади круга
double circle_area(double r) 
{
	return pi * r * r;
}

// Функция для расчета площади прямоугольника
double rectangle_area(double a, double b)
{
	return a * b;
}

// Функция для расчета площади треугольника по формуле Герона
double triangle_area(double a, double b, double c)
{
	double p;
	p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
