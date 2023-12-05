#include <iostream>

//Task1  =
void max_iz_treh(int& a, int& b, int& c)
{
	int max = a;
	if (b > max)
	{
		max = b;
	}
	else
		if (c > max)
		{
			max = c;
		}
	a = b = c = max;
}
//шаблон для вызова массива
template <typename T>
void print_arr(T arr[], const int length)
{
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
//Bозврат отрицательного числа
int& negative_chislo(int arr[], const int length)
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < 0)
			return arr[i];
	}

}
//Обнуление схожих чисел в массиве
void zero_massiv(int* arr, const int length, int* arr2, const int length2)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length2; j++)
		{
			if (*(arr + i) == *(arr2 + j))
			{
				*(arr2 + j) = 0;
				break;
			}
		}
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//Task1
	int A = 3, B = 12, C = 7;
	std::cout << "Дано: " << A << ' ' << B << ' ' << C << std::endl;
	max_iz_treh(A, B, C);
	std::cout << "Получено: " << A << ' ' << B << ' ' << C << "\n\n";

	//Task2
	const int size = 5;
	int arr[size]{ 0, 2, 3, 9, -4 };
	print_arr(arr, size);

	int& result = negative_chislo(arr, size);
	std::cout << "Первое негативное число: " << result << "\n\n";

	//Task3
	const int size1 = 5;
	int arr1[size1]{ 1, 4, 3, 9, 5 };
	print_arr(arr1, size1);

	const int size2 = 5;
	int arr2[size2]{ 0, 2, 3, 9, -4 };
	print_arr(arr2, size2);

	zero_massiv(arr1, size1, arr2, size2);
	std::cout << "Обнуленный массив:\n";
	print_arr(arr2, size2);

	return 0;
}
