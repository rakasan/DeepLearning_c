
#ifndef SIMPLE_NEURAL_NETWORK_H
#define SIMPLE_NEURAL_NETWORK_H

#define HID_LEN                           3
double single_in_single_out(double input, double weight);

double multiple_input_single_out(double * input, double * weigth,int LEN);

void single_in_multiple_out(double input_scalar,double * weigthVector, double * outputVector, int LEN);

void multiple_input_multiple_output_nn(double * input_vector,
                                        int INPUT_LENGTH,
                                        double * output_vector,
                                        int OUTPUT_LENGTH,
                                        double weight_matrix[OUTPUT_LENGTH][INPUT_LENGTH]);

void hidden_layer_nn(double * input_vector,
                     int INPUT_LEN,
                     int HIDDEN_LENGTH,
                     double * in_to_hid_weigth[HIDDEN_LENGTH][INPUT_LEN],
                     int OUTPUT_LENGTH,
                     double * hit_to_out_weigth[OUTPUT_LENGTH][HIDDEN_LENGTH],
                     double * output_vector
                     );

double hidden_pred_vector[HID_LEN];
#endif // SIMPLE_NEURAL_NETWORK_H
