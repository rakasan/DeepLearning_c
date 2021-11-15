
#include "simple_neural_networks.h"
#include "math.h"
#include "stdlib.h"
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

void hidden_layer_nn(double * input_vector,
                     int INPUT_LEN,
                     int HIDDEN_LENGTH,
                     double * in_to_hid_weigth[HIDDEN_LENGTH][INPUT_LEN],
                     int OUTPUT_LENGTH,
                     double * hit_to_out_weigth[OUTPUT_LENGTH][HIDDEN_LENGTH],
                     double * output_vector
                     )
{


    matrix_vector_multiply(input_vector,INPUT_LEN,hidden_pred_vector,OUTPUT_LENGTH,in_to_hid_weigth);
    matrix_vector_multiply(hidden_pred_vector,INPUT_LEN,output_vector,OUTPUT_LENGTH,hit_to_out_weigth);

}

double find_error(double input,double weight,double expected_value)
{
    return powf(((input * weight)-expected_value),2);
}

double find_error_simple(double yhat,double y)
{
    return powf((yhat-y),2);
}


void brute_force_learning(double input,
                          double weight,
                          double expected_value,
                          double step_amount,
                          double itr)
{
    double prediction, error;
    double up_prediction,down_prediction;
    double up_error, down_error;

    for(int i=0;i<itr;i++)
    {
        prediction = input *weight;
        error = powf((prediction - expected_value),2);
        printf("Error : %f Prediction : %f \r\n",error,prediction);

        up_prediction = input *(weight + step_amount);
        up_error = powf((up_prediction - expected_value),2);
      //  printf("Error : %f Prediction : %f",up_error,up_prediction);

        down_prediction = input *(weight - step_amount);
        down_error = powf((down_prediction - expected_value),2);
  //      printf("Error : %f Prediction : %f",down_error,down_prediction);

        if(up_error < down_error)
        {
            weight+=step_amount;
        }
        else
        {
           weight -=step_amount;
       }
    }

}

void normalize_data(double *input_vector,double *output_vector,int length)
{
    double max_value = (input_vector[0] ==0)?1:input_vector[0];

    /* Find the max */
    for(int i=1;i<length;i++)
    {
        if(max_value < input_vector[i])
        {
            max_value = input_vector[i];
        }
        else
        {
            /* Carry on */
        }
    }


    /* Normalize the data */
    for(int i = 0;i<length;i++)
    {
        output_vector[i] = (input_vector[i]/max_value);
    }
}

void weight_random_initialization(int HIDDEN_LEN,
                                  int INPUT_LEN,
                                  double weights_matrix[HIDDEN_LEN][INPUT_LEN])
{
    double d_rand;
/* Seed random number generator */
srand(2);
    for(int i=0;i<HIDDEN_LEN;i++)
    {
        for(int j=0;j<INPUT_LEN;j++)
        {
            /* random numbers 0 and 1 */
            d_rand = (rand() % 10);
            d_rand /= 10;

            weights_matrix[i][j] = d_rand;
        }

    }
}


void normalize_data_2D(int ROW,int COL,double input_maxtrix[ROW][COL],double output_matrix[ROW][COL])
{
    double max_value = (input_maxtrix[0][0] ==0)?1:input_maxtrix[0][0];

    for(int i = 0;i<ROW;i++)
    {
        for(int j = 0;j<COL;j++)
        {
            if(input_maxtrix[i][j] > max_value)
                max_value = input_maxtrix[i][j];
        }
    }
    for(int i = 0;i<ROW;i++)
    {
        for(int j = 0;j<COL;j++)
        {
            output_matrix[i][j] = input_maxtrix[i][j]/max_value;
        }
    }
}

void weight_random_init_1D(double *outputVector,int length)
{
 double d_rand;
    srand(2);
    for(int i = 0;i<length;i++)
    {
        d_rand = rand()%10;
        d_rand /= 10;
        outputVector[i] = d_rand;
    }
}

double sigmoid(double x)
{
    double result = 1/(1 + exp(-x));
    return result;
}

void vector_sigmoid(double *input_vector,double * output_vector,int LEN)
{
    for(int i=0;i<LEN;i++)
    {
        output_vector[i] = sigmoid(input_vector[i]);
    }
}
