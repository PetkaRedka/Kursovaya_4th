#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void sort(double *numbers, int left, int right) // quick sort
{

    double pivot;
    int l_hold = left;
    int r_hold = right;

    //Дадим значение самого левого элемента массива переменной pivot
    pivot = numbers[left];

    while (left < right)
    {
        //Перемещяем указатели left и right пока lеft<pivot, а right>pivot
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            //В последствии элементы меняются местами
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    //Когда right окажется слева от left, pivot меняется местами с right
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;

    //В итоге слева от pivot имеют меньшие значения, справва- большие
    if (left < pivot)
        //Далее алгоритм рекурсиво вызывается для сортировки подмассивов
        sort(numbers, left, pivot - 1);
    if (right > pivot)
        sort(numbers, pivot + 1, right);

}

