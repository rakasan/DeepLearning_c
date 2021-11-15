#include <stdio.h>
#include <stdlib.h>
#include "nn.h"
#include "utilis.h"

int main()
{
    const int nips = 256;
    const int nops = 10;

    float rate = 1.0f;

    const float eta = 0.99f;

    const int nhid = 28;

    const int iterrations = 128;

    const Data data = build("semeion.data",nips,nops);

    const NeuralNetwork_type nn = NNbuild(nips,nhid,nops);

    for(int i=0;i<iterrations;i++)
    {

        shuffle(data);
        float error = 0.0f;

        for(int j = 0;j<data.rows;j++)
        {
            const float * const in = data.in[j];

            const float * const tg = data.target[j];

            error += NNtrain(nn,in,tg,rate);
        }

        printf("Error %.12f :: learning rate %f\n",(double)error/data.rows,(double)rate);

        rate *=eta;
    }

    NNsave(nn,"myModel.nn");
    NNfree(nn);

    const NeuralNetwork_type my_loaded_model = NNload("myModel.nn");
    const float * const in  = data.in[0];
    const float * const tg =  data.target[0];

    const float  * const pd = NNPredict(my_loaded_model,in);

    NNprint(tg,data.nouts);

    NNprint(pd,data.nouts);

    NNfree(my_loaded_model);

    dfree(data);

    return 0;

}
