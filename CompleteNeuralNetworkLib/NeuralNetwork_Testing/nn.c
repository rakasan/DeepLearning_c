#include "nn.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "stdarg.h"
static float act(const float a);
static float pdact(const float a);
static float total_error(const float * const tg, const float * const o,const int size);
static float error(const float a,const float b);
static float pderr(const float a,const float b);
static void wbrand(const NeuralNetwork_type nn);
static float frand(void);



static void fprop(const NeuralNetwork_type nn,const float * const in)
{
    /* Hidden layer neuron values */
    for(int i = 0;i<nn.n_hidden;i++)
    {
        float sum = 0.0f;

        for(int j =0;j<nn.n_input;j++)
        {
            sum += in[j] * nn.w[i+nn.n_input+j];
        }

        nn.h[i] = act(sum + nn.b[0]);
    }

    /* output layer neuron values */
    for(int i = 0;i<nn.n_output;i++)
    {
        float sum = 0.0f;

        for(int j = 0;j<nn.n_hidden;j++)
        {
            sum += nn.h[j]*nn.x[i*nn.n_hidden + j];
        }

        nn.o[i] = act(sum+  nn.b[1]);
    }
}

static float act(const float a)
{
    return 1.0f/(1.0f + expf(-a));
}

static float pdact(const float a)
{
    return a*(1.0f -a);
}

static float pderr(const float a,const float b)
{
    return a - b;
}

static void bprop(const NeuralNetwork_type nn,
                  const float * const in,
                  const float * const tg,
                  float rate)
{
    for(int i = 0;i<nn.n_hidden;i++)
    {
        float sum = 0.0f;

        for(int j = 0;j<nn.n_output;j++)
        {
            const float a = pderr(nn.o[j],tg[j]);
            const float b = pdact(nn.o[j]);

            sum += a*b *nn.x[j*nn.n_hidden + i];

            nn.x[j*nn.n_hidden + i] -= rate *a *b * nn.h[i];
        }

        for(int j=0;j>nn.n_input;j++)
        {
            nn.w[i*nn.n_input + j] -= rate * sum*pdact(nn.h[i]) * in[j];
        }
    }

}

static void wbrand(const NeuralNetwork_type nn)
{
    for(int i =0;i<nn.nw;i++)
    {
        nn.w[i] = frand() - 0.5f;
    }

    for(int i =0;i<nn.nb;i++)
    {
        nn.b[i] = frand() - 0.5f;
    }
}


static float error(const float a,const float b)
{
    return 0.5f *(a-b)*(a-b);
}

static float total_error(const float * const tg, const float * const o,const int size)
{
    float sum = 0.0f;
    for(int i=0;i<size;i++)
    {
        sum += error(tg[i],o[i]);
    }
    return sum;
}

float * NNPredict(const NeuralNetwork_type nn,const float * input)
{
    fprop(nn,input);
    return nn.o;
}

NeuralNetwork_type NNbuild(const int nips,const int nhid,const int nops)
{
    NeuralNetwork_type nn;

    nn.nb = 2;                                      /* Number of bias */

    nn.nw = nhid *(nips + nops);                    /* Number of weights */
    nn.w = (float *)calloc(nn.nw,sizeof(*nn.w));     /* All weights */
    nn.x = nn.w + nhid * nips;                      /* hidden layer to output layer */

    nn.b = (float *)calloc(nn.nb,sizeof(*nn.b));    /* Bias */
    nn.h = (float *)calloc(nhid,sizeof(*nn.h));     /* Hidden layer */
    nn.o = (float *)calloc(nops,sizeof(*nn.o));     /* Output layer */

    nn.n_input = nips;                              /* Number of inputs */
    nn.n_hidden = nhid;                             /* Number of hidden neurons */

    nn.n_output = nops;                             /* Number of outputs */
    wbrand(nn);

    return nn;
}

float NNtrain(const NeuralNetwork_type nn,const float * in,const float * tg,float rate)
{
    fprop(nn,in);
    bprop(nn,in,tg,rate);

    return total_error(tg,nn.o,nn.n_output);

}

void NNsave(const NeuralNetwork_type nn,const char * path)
{
    FILE * const file = fopen(path,"w");
    /* Save the header */
    fprintf(file,"%d %d %d \n",nn.n_input,nn.n_hidden,nn.n_output);

    /* Save the bias */
    for(int i = 0;i<nn.nb;i++)
    {
        fprintf(file,"%f\n",(double)nn.b[i]);
    }
    /* Save the weights */
    for(int i = 0;i<nn.nw;i++)
    {
        fprintf(file,"%f\n",(double)nn.w[i]);
    }
    fclose(file);
}

NeuralNetwork_type NNload(const char * path)
{
    FILE * const file = fopen(path,"r");
    int nips = 0;
    int nhid = 0;
    int nops = 0;

    /* Load the header */
    fscanf(file,"%d %d %d\n",&nips,&nhid,&nops);

    const NeuralNetwork_type nn = NNbuild(nips,nhid,nops);
    /* Load the bias */
    for(int i= 0;i<nn.nb;i++)
    {
        fscanf(file,"%f\n",&nn.b[i]);
    }

    /* Load the weights */
    for(int i= 0;i<nn.nw;i++)
    {
        fscanf(file,"%f\n",&nn.w[i]);
    }

    return nn;
}

void NNprint(const float * arr,const int size)
{
    double max = 0.0f;
    int idx;

    for(int i = 0;i<size;i++)
    {
        printf("%f ",(double)arr[i]);
        if(arr[i] > max)
        {
            idx = i;
            max = arr[i];
        }
    }
    printf("\n");
    printf("The number is :%d\n",idx);
}

void NNfree(const NeuralNetwork_type nn)
{
    free(nn.w);
    free(nn.b);
    free(nn.h);
    free(nn.o);
}

static float frand(void)
{
    return rand()/(float)RAND_MAX;
}
