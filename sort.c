#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void sort(double *numbers, int left, int right) // quick sort
{

    double pivot;
    int l_hold = left;
    int r_hold = right;

    //����� �������� ������ ������ �������� ������� ���������� pivot
    pivot = numbers[left];

    while (left < right)
    {
        //���������� ��������� left � right ���� l�ft<pivot, � right>pivot
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            //� ����������� �������� �������� �������
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
    //����� right �������� ����� �� left, pivot �������� ������� � right
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;

    //� ����� ����� �� pivot ����� ������� ��������, �������- �������
    if (left < pivot)
        //����� �������� ��������� ���������� ��� ���������� �����������
        sort(numbers, left, pivot - 1);
    if (right > pivot)
        sort(numbers, pivot + 1, right);

}

