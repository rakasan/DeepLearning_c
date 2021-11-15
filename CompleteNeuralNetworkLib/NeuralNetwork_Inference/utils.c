#include "utilis.h"

int lns(FILE * const file)
{
    int ch = EOF;
    int lines = 0;
    int pc = '\n';

    while((ch= getc(file))!=EOF)
    {
        if(ch == '\n')
        {
            lines++;
        }

        pc = ch;
    }

    if(pc != '\n')
    {
        lines++;
    }

    rewind(file);
    return lines;
}

char * readLine(FILE * const file)
{
    int ch = EOF;
    int reads = 0;
    int size = 128;

    char * line = (char *)malloc((size)*sizeof(char));

    while((ch = getc(file))!= '\n' && ch !=EOF)
    {
        line[reads++] = ch;
        if(reads+1 ==size)
        {
            line = (char *)realloc((line),(size *=2)*sizeof(char));
        }
    }

    line[reads] = '\0';
    return line;
}

float ** new2D(const int rows, const int cols)
{

    float ** row = (float **)malloc((rows) * sizeof(float *));

    for(int r = 0;r<rows;r++)
    {
        row[r] = (float *)malloc((cols)*sizeof(float));
    }
    return row;
}

Data ndata(const int nips, const int nops,const int rows)
{
    const Data data = {
        new2D(rows,nips),
        new2D(rows,nops),
        nips,
        nops,
        rows
    };

    return data;

}

void parse(const Data data,char * line,const int row)
{
    const int cols = data.nips + data.nouts;

    for(int col = 0;col <cols;col++)
    {
        const float val  = atof(strtok(col == 0?line:NULL," ")); /*  atof - ascii to float
                                                                    strtok -string tokenizer */

        if(col < data.nips)
        {
            data.in[row][col] = val;
        }
        else
        {
            data.target[row][col - data.nips] = val;
        }

    }
}

void dfree(const Data d)
{
    for(int row = 0;row < d.rows;row++)
    {
        free(d.in[row]);
        free(d.target[row]);
    }
    free(d.in);
    free(d.target);
}

void shuffle(const Data d)
{
    for(int a= 0;a<d.rows;a++)
    {
        const int b = rand()%d.rows;
        float * ot = d.target[a];
        float * it = d.in[a];

        d.target[a] = d.target[b];
        d.target[b] = ot;

        d.in[a] = d.in[b];
        d.in[b] = it;
    }
}

Data build(const char * path,const int nips,const int nops)
{
    FILE * file = fopen(path,"r");
    if(file == NULL)
    {
        printf("Could not open the file %s",path);
        printf("Dataset does not exist \n");
        exit(1);
    }
    else
    {
        const int rows = lns(file);
        Data data = ndata(nips,nops,rows);
        for(int row = 0;row < rows;row++)
        {
            char * line = readLine(file);
            parse(data,line,row);
            free(line);
        }
        fclose(file);

        return data;
    }
}
