#include <stdio.h>
#include <stdlib.h>

#include "simple_neural_networks.h"

double weigth = 0.5;
double input = 0.5;
double expected_value = 0.8;
double step_amount = 0.001;

int main()
{
    brute_force_learning(input,weigth,expected_value,step_amount,1300);
    return 0;
}
