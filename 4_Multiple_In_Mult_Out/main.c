#include <stdio.h>
#include <stdlib.h>

#include "simple_neural_networks.h"

#define SAD         0.9
#define SAD_PREDICTION_IDX            0
#define SICK_PREDICTION_IDX               1
#define ACTIVE_PREDICTION_IDX            2

#define IN_LEN                            3

#define OUT_LEN                            3

double predicted_result[3];
                      /*temp     hum      air_q */
double weigths[OUT_LEN][IN_LEN] = {
                        {-2,     9.5,     2.01 }, /* sad */
                        {-0.8,   7.2,     6.3},   /* sick */
                        {-0.5,   0.45,    0.9}    /* active */
                     };
double inputs[IN_LEN] = {30,87,110}; /*temp hum air_q */

int main()
{
    multiple_input_multiple_output_nn(inputs,IN_LEN,predicted_result,OUT_LEN,weigths);
    printf("Sad prediction is %f \r\n",predicted_result[SAD_PREDICTION_IDX]);
    printf("Sick prediction is %f \r\n",predicted_result[SICK_PREDICTION_IDX]);
    printf("Active prediction is %f \r\n",predicted_result[ACTIVE_PREDICTION_IDX]);
    return 0;
}
