#include <stdio.h>
#include <stdlib.h>

#include "simple_neural_networks.h"

#define NUM_OF_FEATURES   2 //n values
#define NUM_OF_EXAMPLES   3 // m values

/* Hours of workout */
double x1[NUM_OF_EXAMPLES] = {2,5,1};
double __x1[NUM_OF_EXAMPLES];

/* Hours of rest */
double x2[NUM_OF_EXAMPLES] = {8,5,8};
double __x2[NUM_OF_EXAMPLES];

/* muscle gain data */
double y[NUM_OF_EXAMPLES] = {200,90,190};
double __y[NUM_OF_EXAMPLES];
int main()
{
    normalize_data(x1,__x1,NUM_OF_EXAMPLES);
    normalize_data(x2,__x2,NUM_OF_EXAMPLES);
    normalize_data(y,__y,NUM_OF_EXAMPLES);

    printf("Raw x1 data: \n\r");
    for(int i = 0;i<NUM_OF_EXAMPLES;i++)
    {
        printf("%f ",x1[i]);
    }
    printf("\n\r");

    printf("Normalized x1 data: \n\r");
    for(int i = 0;i<NUM_OF_EXAMPLES;i++)
    {
        printf("%f ",__x1[i]);
    }
    printf("\n\r");

        printf("Raw x2 data: \n\r");
    for(int i = 0;i<NUM_OF_EXAMPLES;i++)
    {
        printf("%f ",x2[i]);
    }
    printf("\n\r");

    printf("Normalized x2 data: \n\r");
    for(int i = 0;i<NUM_OF_EXAMPLES;i++)
    {
        printf("%f ",__x2[i]);
    }
    printf("\n\r");

        printf("Raw y data: \n\r");
    for(int i = 0;i<NUM_OF_EXAMPLES;i++)
    {
        printf("%f ",y[i]);
    }
    printf("\n\r");

    printf("Normalized y data: \n\r");
    for(int i = 0;i<NUM_OF_EXAMPLES;i++)
    {
        printf("%f ",__y[i]);
    }
    printf("\n\r");
    return 0;
}
