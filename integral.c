#include "density.c"

double integral(double *arr, int a_side, double sigma_sq, double mu)
{
    //������� ���������, �������� � ��������.
    int i = 0;

    //���� ������� ������ ����.
    if (a_side < 0)
    {

        while(arr[i] < ((-1) * a_side))
            i++;
    }
    //���� ������ ����.
    else if (a_side > 0)
    {
        while(arr[i] < a_side)
            i++;
    }
    //���� ����� ����.
    else
        return 1/2;

    //�������� ������ ���������. � ��� ����� �������� �������� ������� ��������� �����������.
    double *a_side_arr, integral = 0;
    a_side_arr = (double*)malloc(i*sizeof(double));

    //������� ��������� �����������.
    density(a_side_arr, arr, i, sigma_sq, mu);

    //������� �������� �������� ������� ��������������� ������� ������
    //�������� ������� ��������� ����������� � ������ ����� � ������� ������
    //�������� �������� 2-� ��������� ����� ��������� ������������� �������.
    for (int j = 1; j<i; j++)
        integral +=  a_side_arr[j]*(arr[j]-arr[j-1]);


    free(a_side_arr);

    //������� �������� ��������� � ����������� �� ��������� ������� ������������ ����.
    if (a_side > 0)
        return 1/2 + integral;

    else
        return 1/2 - integral;

}
