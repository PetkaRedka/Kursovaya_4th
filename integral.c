#include "density.c"

double integral(double *arr, int a_side, double sigma_sq, double mu)
{
    //Счетчик элементов, входящих в интервал.
    int i = 0;

    //Если граница меньше нуля.
    if (a_side < 0)
    {

        while(arr[i] < ((-1) * a_side))
            i++;
    }
    //Если больше нуля.
    else if (a_side > 0)
    {
        while(arr[i] < a_side)
            i++;
    }
    //Если равна нулю.
    else
        return 1/2;

    //Создадим массив элементов. В нем будут хранится значения функций плотности вероятности.
    double *a_side_arr, integral = 0;
    a_side_arr = (double*)malloc(i*sizeof(double));

    //Функция плотности вероятности.
    density(a_side_arr, arr, i, sigma_sq, mu);

    //Считаем интеграл суммирая площади прямоугольников высотой равной
    //значению функции плотности вероятности в данной точке и шириной равной
    //разности соседних 2-х элементов нашей случайной нормированной выборки.
    for (int j = 1; j<i; j++)
        integral +=  a_side_arr[j]*(arr[j]-arr[j-1]);


    free(a_side_arr);

    //Возврат значения интеграла в зависимости от положения границы относительно нуля.
    if (a_side > 0)
        return 1/2 + integral;

    else
        return 1/2 - integral;

}
