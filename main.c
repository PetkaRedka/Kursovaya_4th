#include <time.h>
#include <locale.h>

#define N 50000
#define pi	3.14159265358979323846

#include "sort.c"
#include "integral.c"

double rnd()  //данная функция используется для генерации нормированных случайных величин между 0 и 20
{
    double answer;
    answer = rand() % 20000;
    return (answer/1000);
}


int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    int arr_size = 2*N, a, b, mu, sigma_sq;
    double *arr_numbers, answer;
    arr_numbers = (double*)malloc(arr_size*sizeof(double));  //выделение памяти для массива типа double

    printf("Левая граница: ");
    scanf("%d", &a);
    printf("\nПравая граница: ");
    scanf("%d", &b);

    printf("\nВведеите математическое ожидание: ");
    scanf("%d", &mu);
    printf("\nВведите значение дисперсии: ");
    scanf("%d", &sigma_sq);

    if (sigma_sq <= 0)  //проверка введённой дисперсии
    {
        printf("Невозможное значение дисперсии!");
        return 0;
    }

    for (int i =0; i<=2*N; i++)  //заполнение массива нормированными случайными числами
    {
        arr_numbers[i] = rnd()/sigma_sq;
    }


    sort(arr_numbers, 0, arr_size-1);  //сортировка полученного массива
    answer = integral(arr_numbers, b, sigma_sq, mu) - integral(arr_numbers, a, sigma_sq, mu);  //вычисление вероятности того, попадёт ли случайная величина в заданный интервал
    printf("P = F(b) - F(a) = %.5f", answer);

    free(arr_numbers);  //освобождение памяти
    return 0;
}
