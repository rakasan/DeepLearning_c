#include <stdio.h>
#include <stdlib.h>

#include "simple_neural_networks.h"

double temperature[] = {12,23,50,-10,16};
double weight = -2;

int main()
    {
    printf("First predicted value is %f \r\n",single_in_single_out(temperature[0],weight));
    printf("Second predicted value is %f \r\n",single_in_single_out(temperature[1],weight));
    printf("Third predicted value is %f \r\n",single_in_single_out(temperature[2],weight));
    return 0;
}
