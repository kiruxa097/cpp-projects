/*
	Проект для закрепления большинства изученных скиллов
*/

#include <iostream>
using namespace std;


int days[31], d;  // Глобальные переменные
// Прототипы функций
int day_max_sum(int days[], int d);
int day_min_sum(int days[], int d);

// Основная функция
int main()
{
	int count_sr = 0;  // счетчик дней, в которые траты были больше средних затрат
	double suma = 0;  // Сумма трат за все дни
	cout << "Enter count days: ";
	do  // Проверка корректного ввода, так как программа расчитана на отчет от 1 до 31 дня
	{
		cin >> d;
	} while (d < 1 || d > 31);
	
	for (int i = 0; i < d ; i++)  // Заполнение массива с тратами и подсчет общей суммы
	{
		cout << "Enter amount per day " << i+1 << ": ";
		cin >> days[i];
		suma += days[i];
	}

	cout << "total amount: " << suma << endl;  // Общая сумма
	cout << "average cost amount: " << suma / d << endl;  // Средняя сумма затрат в день
	int maxDay = day_max_sum(days, d);  // Номер дня, в котором была максимальная транзакция
	int minDay = day_min_sum(days, d);  // Номер дня, в котором была минимальная транзакция
	cout << "Maximum expense: " << days[maxDay] << " on day " << maxDay + 1 << endl;
	cout << "Minimum expense: " << days[minDay] << " on day " << minDay + 1 << endl;
	
	for (int i = 0; i < d; i++)  // Подсчет кол-ва дней, в которых затраты больше чем средние
	{
		if (days[i] > suma / d) count_sr += 1;
	}
	cout << "Number of days when expenses are above average: " << count_sr << endl;
	return 0;
}
// Функция поиска дня, в котором была наибольшая транзация
int day_max_sum(int days[], int d)
{
	int t = 0;
	for (int i = 0; i < d; i++)
	{
		if (days[i] > days[t]) t = i;
	}
	return t;
}
// Функция поиска дня, в котором была наименьшая транзация
int day_min_sum(int days[], int d)
{
	int t = 0;
	for (int i = 0; i < d; i++)
	{
		if (days[i] < days[t]) t = i;
	}
	return t;
}
