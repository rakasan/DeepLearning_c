
typedef struct
{
    float *w; /* All weights */
    float *x;/* hidden layer to output layer */
    float *b; /* Bias */
    float *h;/* Hidden layer */
    float *o;/* Output layer */
    int nb; /* Number of bias */
    int nw; /* Number of weights */
    int n_input; /* Number of inputs */
    int n_hidden; /* Number of hidden neurons */
    int n_output; /* Number of outputs */

}NeuralNetwork_type;


float * NNPredict(const NeuralNetwork_type nn,const float * input);
NeuralNetwork_type NNbuild(const int nips,const int nhid,const int nops);
float NNtrain(const NeuralNetwork_type nn,const float * in,const float * tg,float rate);
void NNsave(const NeuralNetwork_type nn,const char * path);
NeuralNetwork_type NNload(const char * path);
void NNprint(const float * arr,const int size);
void NNfree(const NeuralNetwork_type nn);
