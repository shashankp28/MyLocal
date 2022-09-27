#include <stdio.h>
#include <math.h>
int main()
{
    int N, X, i, z=1000000007, j;
    double p;
    scanf("%d %d", &N, &X);
    int arr[N];
    for(i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=N-1; i>=0; i--)
    {
        for(j=0; ;j++)
        {
            p = z*(j/(double)arr[i]) + X/(double)arr[i];
            if(ceil(p) == p)
            {
                X = (int)p;
                break;
            }
        }
    }
    printf("%d", X);
    return 0;
}
