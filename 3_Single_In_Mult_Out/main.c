#include <stdio.h>
#include <stdlib.h>

#include "simple_neural_networks.h"

#define SAD         0.9
#define TEMPERATURE_PREDICTION_IDX            0
#define HUMIDITY_PREDICTION_IDX               1
#define AIR_QUALITY_PREDICTION_IDX            2

#define VECTOR_LEN                            3

double predicted_result[3];

double weight[3] = {-20,95,201}; /*temperature,humidity,air_q */

int main()
{
    single_in_multiple_out(SAD,weight,predicted_result,VECTOR_LEN);
    printf("Predicted temperature is %f \r\n",predicted_result[TEMPERATURE_PREDICTION_IDX]);
    printf("Predicted humidity is %f \r\n",predicted_result[HUMIDITY_PREDICTION_IDX]);
    printf("Predicted air quality is %f \r\n",predicted_result[AIR_QUALITY_PREDICTION_IDX]);
    return 0;
}
