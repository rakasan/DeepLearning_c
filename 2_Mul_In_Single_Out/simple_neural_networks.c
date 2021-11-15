
#include "simple_neural_networks.h"

double weighted_sum(double * input, double * weigth,int LEN)
{
    double output;

    for(int i =0;i<LEN;i++)
    {
        output += (input[i] * weigth[i]);
    }

    return output;
}

double multiple_input_single_out(double * input, double * weigth,int LEN)
{
    double predicted_value;

    predicted_value = weighted_sum(input,weigth,LEN);

    return predicted_value;
}

double single_in_single_out(double input, double weight)
{
    return (input * weight);
}
