#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void density(double *norm_b, double *b_side, int count_b, double sigma_sq, double mu)
{
    for (int i = 0; i<count_b; i++) // плотность вероятности по формуле
    {
        norm_b[i] = 1/sqrt(2*pi*sigma_sq) * exp(-pow(b_side[i] - mu,2)/(2*sigma_sq));
    }
}

