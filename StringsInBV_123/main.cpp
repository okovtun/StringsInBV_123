#include<iostream>
#include<Windows.h>

//VCS - Version Control System
//SVN, Sumversion, Mercury.....
//Git != GitHub
//Git - Система контроля версий
//GitHub - Облачное хранилище

//Репозиторий
//Удаленный (remote)
//push, pull и fetch

//COMMIT - это контрольная точка
//Branches		master, main

/*
TODO:
Написать функции:
bool is_palindrome(char str[]);	//Проверяет, является ли строка палиндромом (ого, или, 12321)
bool is_int_number(char str[]);	//Проверяет, является ли строка целым десятичным числом
int  to_int_number(char str[]);	//Если строка - десятичное число, то функция возвращает его int-овое значение.
bool is_bin_number(char str[]);	//Проверяет, является ли строка двоичным числом
int  bin_to_dec(char str[]);	//Если строка - двоичное число, то функция возвращает его десятичное значение.
bool is_hex_number(char str[]);	//Проверяет, является ли строка шестнадцатеричным числом
int  hex_to_dec(char str[]);	//Если строка - шестнадцатеричное число, то функция возвращает его десятичное значение.

*/

int StringLength(char str[]);
void to_upper(char str[]);
void shrink(char str[]);		//Удаляет лишние пробелы между словами в предложении
//Харашо       живьет   на    свете     Винни-Пух
//Харашо живьет на свете Винни-Пух
//HELLO
void remove_symbol(char str[], char symbol);
bool is_palindrome(char str[]);	//Прототип функции (Объявление функции - Function declaration)
bool is_int_number(char str[]);

void main()
{
	using namespace std;
	/*for(;;)
	{
		cout << "Hello World";
	}*/
	//setlocale(LC_ALL, "Russian");
	//C char 
	//ASCII-символ с кодом 0 - '\0'
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	/*char str[] = "Hello World!";
	cout << str << endl;
	cout << sizeof(str) << endl;*/

	//for (int i = 0; i < 256; i++)cout << i << "\t" << (char)i << endl;

	/*cout << 'A' << "\t" << 'a' << endl;
	cout << (int)'A' << "\t" << (int)'a' << endl;
	cout << 'A' - 'a' << endl;*/

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int n = 256;
	//char str[n] = "Харашо       живьет   на    свете     Винни-Пух";
	char str[n] = "Аргентина манит негра";
	cout << "Введите строку: "; //cin >> str;
	cin.getline(str, n);
	//SetConsoleCP(866);
	cout << str << endl;
	//cout << typeid(str).name() << endl;
	//cout << StringLength(str) << endl;
	//to_upper(str);
	shrink(str);
	cout << str << endl;

	//cout << is_palindrome(str) << endl;
	/*if (is_palindrome(str))
	{
		cout << "Введенная строка - палиндром" << endl;
	}
	else
	{
		cout << "Введенная строка - НЕ палиндром" << endl;
	}
	cout << str << endl;*/
	if (is_int_number(str))
	{
		cout << "Строка - число!" << endl;
	}
	else
	{
		cout << "Строка - НЕ число!" << endl;
	}
	/*char* dynamic_string = new char[255];
	cout << "Введите строку: ";
	cin >> dynamic_string;
	cout << dynamic_string << endl;
	delete[] dynamic_string;*/
}

int StringLength(char str[])
{
	std::cout << typeid(str).name() << std::endl;
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'a' && str[i] <= 'z' ||
			str[i] >= 'а' && str[i] <= 'я'
			)//Если элемент строки - маленькая буква
			str[i] -= 32;	//то переводим его в верхний регистр.
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
				str[j] = str[j + 1];
		}
	}
}
void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
				str[j] = str[j + 1];
		}
	}
}
bool is_palindrome(char* str)	//Реализация функции (Определение функции - Function definition)
{
	//int n = StringLength(str);//Вызываем функцию StringLength(), для того чтобы посчитать размер строки 
								//(количество символов в строке)
	int n = strlen(str);	//Встроенная функция, которая возвращает длину строки в символах
								//1) Для того чтобы исходная строка НЕ изменилась, создаем буферную строку
	char* buffer = new char[n + 1]{};	//{} - инициализируют выделяемую память значениями по умолчанию
										//{} - зануляют выделяемую память
	//for (int i = 0; i < n; i++)buffer[i] = *(str + i);
		//buffer[i] = str[i];
	strcpy(buffer, str);	//Встроенная функция, которая копирует одну строку в другую
	//strcpy(dst, src);	//dst(destination) - строка получатель, src(source) - строка источник.
	//strcpy(куда, откуда);

	to_upper(buffer);
	remove_symbol(buffer, ' ');
	n = StringLength(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))//ЕСЛИ элемент строки НЕ цифра
			return false;
	}
	return true;
}