#include <stdio.h>
#include <stdlib.h>

#include "simple_neural_networks.h"

#define NUM_OF_FEATURES   2 //n values
#define NUM_OF_EXAMPLES   3 // m values

#define NUM_OF_HID_NODES      3
#define NUM_OF_OUTPUT_NODES     1



/* Input layer to hidden layer weights buffer */
double syn0[NUM_OF_HID_NODES][NUM_OF_FEATURES];

/* Hidden layer to output layer  */
double syn1[NUM_OF_HID_NODES];

double raw_x[NUM_OF_FEATURES][NUM_OF_EXAMPLES] = {  {2,5,1},
                                                    {8,5,8}};
double raw_y[1][NUM_OF_EXAMPLES] = {200,90,190};

/* Train x
    2/8 5/8 1/8
    8/8 5/8 8/8
    dim = nx X m
*/
double train_x[NUM_OF_FEATURES][NUM_OF_EXAMPLES];

/* Train y
    200/200 90/200 190/200
    dim = 1 X m
*/
double train_y[1][NUM_OF_EXAMPLES];

double train_x_eg1[NUM_OF_FEATURES];
double train_y_eg1;
double z1_eg1[NUM_OF_HID_NODES];
double a1_eg1[NUM_OF_HID_NODES];
double z2_eg1;
double yhat_eg1;
int main()
{

/* Normalize X and Y */
normalize_data_2D(NUM_OF_FEATURES,NUM_OF_EXAMPLES,raw_x,train_x);
normalize_data_2D(1,NUM_OF_EXAMPLES,raw_y,train_y);


train_x_eg1[0] = train_x[0][0];
train_x_eg1[1] = train_x[1][0];

train_y_eg1 = train_y[0][0];

printf("train_x_eg1 is [%f %f]",train_x_eg1[0],train_x_eg1[1]);
printf("\n\r");
printf("\n\r");
printf("train_y_eg1 is %f",train_y_eg1);

/* Initialization syn0 */
weight_random_initialization(NUM_OF_HID_NODES,NUM_OF_FEATURES,syn0);

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

weight_random_init_1D(syn1,NUM_OF_OUTPUT_NODES);
    printf("Synapse 1 \n\r");
    /*synapse 1 weights  */
    for(int i=0;i<NUM_OF_OUTPUT_NODES;i++)
    {
        printf("Synapse 1 [%f %f %f]",syn1[i]);
    }

         printf("\n\r");
        printf("\n\r");

    /* Compute z1 */
    multiple_input_multiple_output_nn(train_x_eg1,NUM_OF_FEATURES,z1_eg1,NUM_OF_HID_NODES,syn0);
      printf("z_eg1  = [%f %f %f]",z1_eg1[0],z1_eg1[1],z1_eg1[2]);
       printf("\n\r");
        printf("\n\r");

    /* Compute A1 */
    vector_sigmoid(z1_eg1,a1_eg1,NUM_OF_HID_NODES);
    printf("a_eg1  = [%f %f %f]",a1_eg1[0],a1_eg1[1],a1_eg1[2]);

    /* Compute z2 */
    z2_eg1 = multiple_input_single_out(a1_eg1,syn1,NUM_OF_HID_NODES);

    printf("\n\r");
    printf("\n\r");

    printf("z2_eg1 %f", z2_eg1);

    /* Compute yhat */
    yhat_eg1 = sigmoid(z2_eg1);

        printf("\n\r");
    printf("\n\r");

    printf("yhat_eg1 %f", yhat_eg1);
    return 0;
}
