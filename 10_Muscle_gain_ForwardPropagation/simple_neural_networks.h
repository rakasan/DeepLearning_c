
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

double find_error_simple(double yhat,double y);

double find_error(double input,double weight,double expected_value);

void brute_force_learning(double input,
                          double weight,
                          double expected_value,
                          double step_amount,
                          double itr);

void normalize_data(double *input_vector,double *output_vector,int length);

void weight_random_initialization(int HIDDEN_LEN,
                                  int INPUT_LEN,
                                  double weights_matrix[HIDDEN_LEN][INPUT_LEN]);

void normalize_data_2D(int ROW,int COL,double input_maxtrix[ROW][COL],double output_matrix[ROW][COL]);

void weight_random_init_1D(double *outputVector,int length);

void vector_sigmoid(double *input_vector,double * output_vector,int LEN);

double sigmoid(double x);

double hidden_pred_vector[HID_LEN];
#endif // SIMPLE_NEURAL_NETWORK_H
