#include <stdio.h>
#include <time.h>
int main()
{
    clock_t t;
    t = clock();
    for(int i=0; i<10000; i++) 
    {
        printf("%d\n", i);
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time Taken: %lf", time_taken);
    return 0;
}