#include "main.h"

// задание 1.a
void task1a()
{
	unsigned char x;
	unsigned char mask;

	mask = 1;
	x = 255;
	cout << "Задание 1.a.\n";
	x = (x & ~(mask << 4)); // бит-маска вида 11101111
	cout << "Результат: " << bitset<8>(x) << "\n";
}

// задание 1.b
void task1b()
{
	unsigned char x;
	unsigned char mask;

	mask = 1;
	x = 0;
	cout << "Задание 1.b.\n";
	x = (x | (mask << 6)); // бит-маска вида 01000000
	cout << "Результат: " << bitset<8>(x) << "\n";
}

// задание 1.c
void task1c()
{
	unsigned int x;
	unsigned int mask;
	const int n = sizeof(int) * 8;

	mask = 1;
	cout << "Задание 1.c.\nВвод 32-разрядного двоичного x: ";
	cin >> x;
	mask = (1 << (n - 1));
	cout << "Начальный вид маски: " << bitset<n>(mask) << "\nРезультат: ";
	for (int i = 1; i <= n; i++)
	{
		cout << ((x & mask) >> (n - i)); // вывод i-ого бита числа
		mask = mask >> 1;
	}
	cout << "\n";
}

// задание 2a
void task2a()
{
	unsigned char mask;
	unsigned char n;
	int arr[8];
	int size;

	cout << "Задание 2.a.\nВвод размера массива: ";
	cin >> size;
	cout << "Ввод элементов массива: ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	n = 0;
	mask = 1;
	for (int i = 0; i < size; i++)
		n = n | (mask << arr[i]);

	cout << "Отсотрированный массив: ";
	for (int i = 0; i < 8; i++)
	{
		if ((n >> i) & 1)
			cout << i << " ";
	}
	cout << "\n";
}

// задание 2b
void task2b()
{
	unsigned long long n;
	unsigned long long mask;
	int arr[64];
	int size;

	cout << "Задание 2.b.\nВвод размера массива: ";
	cin >> size;
	cout << "Ввод элементов массива: ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	n = 0;
	mask = 1;
	for (int i = 0; i < size; i++)
		n = n | (mask << arr[i]); // заполнение битового массива

	cout << "Отсотрированный массив: ";
	for (int i = 0; i < 64; i++)
	{
		if ((n >> i) & 1) // вывод отсортированных чисел
			cout << i << " ";
	}
	cout << "\n";
}

// задание 2c
void task2c()
{
	unsigned char bytearr[8];
	unsigned char mask;
	int arr[64];
	int size;

	cout << "Задание 2.c.\nВвод размера массива: ";
	cin >> size;
	cout << "Ввод элементов массива: ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	mask = 1;
	for (int i = 0; i < size; i++)
		bytearr[7 - (arr[i]) / 8] |= (mask << (arr[i] % 8)); // заполнение битового массива

	for (int i = 63; i >= 0; i--)
	{
		if ((bytearr[i / 8] >> (7 - i % 8)) & 1) // вывод отсортированных чисел
			cout << 63 - i << " ";
	}
	cout << "\n";
}

// функция заполнение файла ввода исходными данными
void filling_file(unsigned int size)
{
	fstream writefile;
	vector<unsigned int> fill;

	writefile.open("input.txt", fstream::out);
	for (unsigned int i = 0; i < size; i++)
		fill.push_back(i);

	random_shuffle(fill.begin(), fill.end()); // случайно перемешиваем массив, заполненный от 0 до size
	for (int i = 0; i < size; i++)
		writefile << fill[i] << " "; // запись входных данных в файл
	writefile.close();
}

// задание 3
void task3()
{
	chrono::system_clock::time_point start_t;
	chrono::system_clock::time_point end_t;
	double duration_t;
	fstream writefile;
	fstream readfile;
	unsigned char *bytearr = new unsigned char[1250000];
	unsigned int n;
	unsigned char mask;

	start_t = chrono::system_clock::now();

	readfile.open("input.txt", fstream::in);
	writefile.open("output.txt", fstream::out);

	mask = 1;
	while (!readfile.eof())
	{
		readfile >> n; // чтение чисел из файла
		bytearr[1249999 - n / 8] |= (mask << (n % 8)); // заполнение битового массива
	}

	for (int i = 9999999; i >= 0; i--)
	{
		if ((bytearr[i / 8] >> (7 - i % 8)) & 1) // вывод отсортированных чисел
			writefile << 9999999 - i << " ";
	}

	end_t = chrono::system_clock::now();

	readfile.close();
	writefile.close();

	duration_t = chrono::duration<double>(end_t - start_t).count();
	cout << "Время выполнения: " << duration_t << "s\n";
	cout << "Объём выделяемой памяти: " << sizeof(unsigned char) * 1250000 << " Б\n";
}

int main(void)
{
////	Задание 1
	task1a();
	task1b();
	task1c();

////	Задание 2
	task2a();
	task2b();
	task2c();

////	Задание 3
	filling_file(10000000);
	task3();
}