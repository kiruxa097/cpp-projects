/*
  Демонстрация метода пузырьковой сортировки
*/
#include <iostream>
#include <cstdlib>
#include <ctime>


int main() {
	int nums[10];
	int a, b, t;
	int size;
	
	size = 10;  // Кол-во элементов в массиве

	srand(time(0)); // Каждый раз в массиве будут новые числа, чтобы убедиться в работе пузырьковой сортировки
	
	// Помещаем в массив случайные числа
	for (t = 0; t < size; t++) nums[t] = rand();

	// Отображаем исходный массив
	std::cout << "Original array is: \n";
	for (t = 0; t < size; t++) std::cout << nums[t] << " ";
	std::cout << "\n";

	// Реализация алгоритма пузырьковой сортировки
	for (a = 1; a < size; a++) {
		for (b = size - 1; b >= a; b--) {
			if (nums[b - 1] > nums[b]) {
				t = nums[b - 1];
				nums[b - 1] = nums[b];
				nums[b] = t;
			}
		}
	}
	// Отображаем отсортированный массив
	std::cout << "\nSorted array is:\n";
	for (t = 0; t < size; t++) std::cout << nums[t] << " ";
	return 0;
}
