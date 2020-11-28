#include <locale.h>	//нужна для подключения русского языка
#include <stdio.h>	//основная библиотека 
#include <math.h>	//нужна для подсчета е^x

int N_Slag(double x);					// поиск n
void e(double x, int n);				// вычисление e^x
double Eps = 0.000001;					// Точность

int main() {
	setlocale(LC_ALL, "Russian");		// подключаю русский язык
	double	a = 5;						// верхняя граница значений х
	double	b = 0;						// нижняя граница значений х
	double	x = a;						// переменная
	double Slag = 1;					// слагаемое
	double Sum = 1;						// Текущая сумма
	int	n = N_Slag(a);					// колличество членов ряда
	int k = 0;							// вспомогательная переменная
	// считаем необходимое колличество членов ряда
	if (N_Slag(b) > n)				
		{ n = N_Slag(b); }
	//печать таблицы
	for (double i = 0; i <= 4.01; i = i + 0.10)
	{
		e(i, n);
		k++;
		if (k % 9 == 0)
			printf("\n");
	}
	printf("\n");
}

int N_Slag(double x) {
	double Slag = 1;					// слагаемое
	int i = 0;							// счетчик
	while (Slag > Eps)
	{
		i++;
		Slag = Slag * x / i;
	}
	return i;
}

void e(double	x, int n) {
	double Slag = 1;					// слагаемое
	double Sum = 1;						// Текущая сумма
	double Tsum = exp(x);
	for (int i = 1; i < n; i++)
	{
		Slag = Slag * x / i;
		Sum = Sum + Slag;
	}
	printf("%.8f\t", Sum);
	if (fabs(Tsum - Sum) > Eps) { printf("Ошибка%.8f", Tsum); }
}