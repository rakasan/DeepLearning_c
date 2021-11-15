
#ifndef SIMPLE_NEURAL_NETWORK_H
#define SIMPLE_NEURAL_NETWORK_H
double single_in_single_out(double input, double weight);

double multiple_input_single_out(double * input, double * weigth,int LEN);

void single_in_multiple_out(double input_scalar,double * weigthVector, double * outputVector, int LEN);

void multiple_input_multiple_output_nn(double * input_vector,
                                        int INPUT_LENGTH,
                                        double * output_vector,
                                        int OUTPUT_LENGTH,
                                        double weight_matrix[OUTPUT_LENGTH][INPUT_LENGTH]);

#endif // SIMPLE_NEURAL_NETWORK_H
