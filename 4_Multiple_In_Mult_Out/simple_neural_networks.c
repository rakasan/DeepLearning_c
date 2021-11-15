
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


void elementwise_multiply(double input_scalar,double * weigthVector, double * outputVector, int LEN)
{
    for(int i = 0;i<LEN;i++)
    {
        outputVector[i] = input_scalar * weigthVector[i];
    }
}

void single_in_multiple_out(double input_scalar,double * weigthVector, double * outputVector, int LEN)
{
    elementwise_multiply(input_scalar,weigthVector,outputVector,LEN);
}


void matrix_vector_multiply(double * input_vector,
                            int INPUT_LENGTH,
                            double * output_vector,
                            int OUTPUT_LENGTH,
                            double weight_matrix[OUTPUT_LENGTH][INPUT_LENGTH])
{
    for(int k = 0;k<OUTPUT_LENGTH;k++)
    {
        for(int i=0;i<INPUT_LENGTH;i++)
        {
            output_vector[k] +=input_vector[i]*weight_matrix[k][i];
        }
    }
}

void multiple_input_multiple_output_nn(double * input_vector,
                                        int INPUT_LENGTH,
                                        double * output_vector,
                                        int OUTPUT_LENGTH,
                                        double weight_matrix[OUTPUT_LENGTH][INPUT_LENGTH])
{

    matrix_vector_multiply(input_vector,INPUT_LENGTH,output_vector,OUTPUT_LENGTH,weight_matrix);
}
