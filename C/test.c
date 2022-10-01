#include<stdio.h>
#include<stdlib.h>

int find(int *a, int low, int high)
{
    if(low+1>=high) return a[low]+1;
    int mid = (low+high)/2;
    if(a[low]-low!=a[mid]-mid) return find(a, low, mid);
    else if(a[mid]-mid!=a[high]-high) return find(a, mid, high);
}

int main()
{
    int n=1000;
    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<=n; i++)
    {
        if(i==9*n/10) i++;
        arr[i] = i;
    }

    printf("%d")
    int start=0, end=n-1;
    if(arr[start]!=0) printf("%d", 0);
    else if(arr[end]!=n) printf("%d", n);
    else printf("%d", find(arr, start, end));
    return 0;
}