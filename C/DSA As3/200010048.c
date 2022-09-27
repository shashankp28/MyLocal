#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start, end;
double cpu_time_used;
int main(int argc, char **argv)
{
    start = clock();
    if(argc>2)
    {
        printf("PLEASE ENTER ONLY TWO PARAMETERS");
        exit(1);
    }
    if(argc<2)
    {
        printf("PLEASE ENTER TWO PARAMETERS");
        exit(1);
    }
    FILE* f;
    f = fopen(argv[1], "r");
    if(f==NULL)
    {
        printf("FILE NOT FOUND");
        exit(2);
    }
    int n=0;
    char c[1000];
    while(fgets(c, 999, f)!= NULL)
    {
        n++;
    }
    fclose(f);
    if(n==0)
    {
        printf("NO NUMBERS PRESENT");
        exit(3);
    }
    int arr[n], temp[n], at[n], dc[10], i=0, j=0, k=0;
    f = fopen(argv[1], "r");
    while(fgets(c, 999, f)!= NULL)
    {
        arr[i] = atoi(c);
        i++;
    }
    fclose(f);
    while(1)
    {
        for(i=0; i<10; i++)
        {
            dc[i] = 0;
        }
        for(i=0; i<n; i++)
        {
            at[i] = (arr[i]/(int)pow(10, j))%10;
            dc[at[i]]++;
            k = at[i]==0 ? k+1 : k;
        }
        if(k==n)
        {
            break;
        }
        for(i=1; i<10; i++)
        {
            dc[i] += dc[i-1];
        }
        for(i=n-1; i>=0; i--)
        {
            temp[dc[at[i]]-1] = arr[i];
            dc[at[i]]--;
        }
        for(i=0; i<n; i++)
        {
            arr[i] = temp[i];
        }
        j++;
        k=0;
    }
    FILE* g;
    g = fopen("radix.txt", "w+");
    for(i=0; i<n; i++)
    {
        fprintf(g, "%d\n", arr[i]);
    }
    fclose(g);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f", cpu_time_used);
    return 0;
}
