#include <stdio.h>
#include <stdlib.h>

#include "simple_neural_networks.h"

#define NUM_OF_FEATURES   2 //n values
#define NUM_OF_EXAMPLES   3 // m values

#define NUM_OF_HID_NODES      3
#define NUM_OF_OUTPUT_NODES     1

/* Hours of workout */
double x1[NUM_OF_EXAMPLES] = {2,5,1};
double __x1[NUM_OF_EXAMPLES];

/* Hours of rest */
double x2[NUM_OF_EXAMPLES] = {8,5,8};
double __x2[NUM_OF_EXAMPLES];

/* muscle gain data */
double y[NUM_OF_EXAMPLES] = {200,90,190};
double __y[NUM_OF_EXAMPLES];

/* Input layer to hidden layer weights buffer */
double syn0[NUM_OF_HID_NODES][NUM_OF_FEATURES];

/* Hidden layer to output layer  */
double syn1[NUM_OF_OUTPUT_NODES][NUM_OF_HID_NODES];
int main()
{

    weight_random_initialization(HID_LEN,NUM_OF_FEATURES,syn0);
    weight_random_initialization(NUM_OF_OUTPUT_NODES,NUM_OF_HID_NODES,syn1);

    printf("synapse 0 \n\r");
    /*synapse 0 weights  */
    for(int i=0;i<NUM_OF_HID_NODES;i++)
    {
        for(int j = 0;j<NUM_OF_FEATURES;j++)
        {
            printf("Weight %f ",syn0[i][j]);
        }
        printf("\n\r");
        printf("\n\r");
    }
    printf("Synapse 1 \n\r");
    /*synapse 1 weights  */
    for(int i=0;i<NUM_OF_OUTPUT_NODES;i++)
    {
        for(int j = 0;j<NUM_OF_HID_NODES;j++)
        {
            printf("Weight %f ",syn1[i][j]);
        }
        printf("\n\r");
        printf("\n\r");
    }

    return 0;
}
