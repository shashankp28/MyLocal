#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int l, int m, int h)
{
    int i=l, j=m+1, temp[h-l+1], k=0;
    while(i<=m && j<=h)
    {
        if(arr[i]<arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=h)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    k = 0;
    for(i=l; i<=h; i++)
    {
        arr[i] = temp[k];
        k++;
    }
}
void mergesort(int arr[], int l, int h)
{
    if(l<h)
    {
        int m;
        m = (l+h)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, h);
        merge(arr, l, m, h);
    }
}
int main(int argc, char **argv)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    if(argc>2)
    {
        printf("PLEASE ENTER ONLY ONE FILE NAME");
        exit(1);
    }
    if(argc<2)
    {
        printf("PLEASE ENTER A FILE NAME");
        exit(1);
    }
    FILE* f;
    f = fopen(argv[1], "r");
    if(f==NULL)
    {
        printf("FILE NOT FOUND");
        exit(2);
    }
    int n=0, i=0;
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
    int arr[n];
    f = fopen(argv[1], "r");
    while(fgets(c, 999, f)!= NULL)
    {
        arr[i] = atoi(c);
        i++;
    }
    mergesort(arr, 0, n-1);
    FILE* g;
    g = fopen("mergesort.txt", "w+");
    for(i=0; i<n; i++)
    {
        fprintf(g, "%d\n", arr[i]);
    }
    fclose(f);
    fclose(g);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f", cpu_time_used);
    return 0;
}
