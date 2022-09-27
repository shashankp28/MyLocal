#include <stdio.h>
int main()
{
    float inp[4][3], out[4][3], w1w1=0, w2w2=0, w1v3=0, w2v3=0, w1v2=0;
    int i, j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%f", inp[i][j]);
        }
    }
    for(j=0; j<3; j++)
    {
        out[0][j] = inp[0][j];
    }
    for(j=0; j<3; j++)
    {
        w1w1 = w1w1 + out[0][j]*out[0][j];
    }
    for(j=0; j<3; j++)
    {
        w1v2 = w1v2 + out[0][j]*inp[1][j];
    }
    for(j=0; j<3; j++)
    {
        w1v3 = w1v3 + out[0][j]*inp[1][j];
    }
    for(j=0; j<3; j++)
    {
        out[1][j] = inp[1][j] - ;
    }

   return 0;
}

