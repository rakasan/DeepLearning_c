#include <stdio.h>
#include <stdlib.h>

#include "simple_neural_networks.h"

#define SAD         0.9
#define SAD_PREDICTION_IDX                0
#define SICK_PREDICTION_IDX               1
#define ACTIVE_PREDICTION_IDX             2

#define IN_LEN                            3
#define OUT_LEN                           3


double predicted_result[3];
                      /*temp     hum      air_q */
double input_to_hidden_weigths[HID_LEN][IN_LEN] = {
                        {-2,     9.5,     2.01 }, /* hid[0] */
                        {-0.8,   7.2,     6.3},   /* hid[1] */
                        {-0.5,   0.45,    0.9}    /* hid[2] */
                     };

                      /*temp     hum      air_q */
double hidden_to_output_weigths[OUT_LEN][HID_LEN] = {
                        {-1.0,     1.15,     0.11 },   /* sad */
                        {-0.18,    0.15,     -0.01},   /* sick */
                        {0.25,    -0.25,    -0.1}     /* active */
                     };
double inputs[IN_LEN] = {30,87,110}; /*temp hum air_q */

int main()
{
  //  multiple_input_multiple_output_nn(inputs,IN_LEN,predicted_result,OUT_LEN,weigths);
    hidden_layer_nn(inputs,IN_LEN,HID_LEN,input_to_hidden_weigths,OUT_LEN,hidden_to_output_weigths,predicted_result);
    printf("Sad prediction is %f \r\n",predicted_result[SAD_PREDICTION_IDX]);
    printf("Sick prediction is %f \r\n",predicted_result[SICK_PREDICTION_IDX]);
    printf("Active prediction is %f \r\n",predicted_result[ACTIVE_PREDICTION_IDX]);
    return 0;
}
