/*
	Мини прога для тренировки низкоуровненных навыков работы с указателями, массивами символов и функциями <cstring> (C-style)
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	char string[1000];  //указываем длину буд. строки (для демонстрации работы программы, укажем 1000)
	cout << "Enter string: ";
	cin.getline(string, 1000);
	char *start, *end;  //указатели начали и конца строки
	int len;  //переменная, хранящая длину строки
	char t;  //переменная, которая будет содержать какое-либо из (start/end), чтобы поменять их местами

	cout << "Start string: " << string << "\n";
	
	len = strlen(string);
	start = string;  //start = string[0]
	end = &string[len-1];  //ссылаемся на последний символ строки(не 0!)

	while (start < end) {  //цикл, который меняет местами символы
		t = *start;
		*start = *end;
		*end = t;
		start++;
		end--;
	}
	
	cout << "Reversed string: " << string;
	
	return 0;
}
