#include <time.h>
#include <locale.h>

#define N 50000
#define pi	3.14159265358979323846

#include "sort.c"
#include "integral.c"

double rnd()  //������ ������� ������������ ��� ��������� ������������� ��������� ������� ����� 0 � 20
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
    arr_numbers = (double*)malloc(arr_size*sizeof(double));  //��������� ������ ��� ������� ���� double

    printf("����� �������: ");
    scanf("%d", &a);
    printf("\n������ �������: ");
    scanf("%d", &b);

    printf("\n�������� �������������� ��������: ");
    scanf("%d", &mu);
    printf("\n������� �������� ���������: ");
    scanf("%d", &sigma_sq);

    if (sigma_sq <= 0)  //�������� �������� ���������
    {
        printf("����������� �������� ���������!");
        return 0;
    }

    for (int i =0; i<=2*N; i++)  //���������� ������� �������������� ���������� �������
    {
        arr_numbers[i] = rnd()/sigma_sq;
    }


    sort(arr_numbers, 0, arr_size-1);  //���������� ����������� �������
    answer = integral(arr_numbers, b, sigma_sq, mu) - integral(arr_numbers, a, sigma_sq, mu);  //���������� ����������� ����, ������ �� ��������� �������� � �������� ��������
    printf("P = F(b) - F(a) = %.5f", answer);

    free(arr_numbers);  //������������ ������
    return 0;
}
