#include "nn.h"
#include "utilis.h"

int main()
{
    const int nips = 256;
    const int nops = 10;

    const Data inference = build("test.data",nips,nops);

    const NeuralNetwork_type loaded_model = NNload("myModel_2.nn");

    const float * const in = inference.in[1];
    const float * const pd = NNPredict(loaded_model,in);

    NNprint(pd,inference.nouts);

    NNfree(loaded_model);
    dfree(inference);

    return 0;
}
