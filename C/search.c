#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

const int MAX = 100;
int *binarySearch(int a[][MAX], int n, int m, int k, int x)
// x is the row number
{
 
    int l = 0, r = m - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
 
        if (a[x][mid] == k)
        {
            return {x, mid} 
//             cout << "Found at (" << x << "," << mid << ")" << endl;
//             return;
        }
 
        if (a[x][mid] > k)
            r = mid - 1;
        if (a[x][mid] < k)
            l = mid + 1;
    }
    return {-1, -1};
}
 
int *findRow(int a[][MAX], int n, int m, int k)
{
 
    int l = 0, r = n - 1, mid;
 
    while (l <= r)
    {
        mid = (l + r) / 2;
 
        // we'll check the left and
        // right most elements
        // of the row here itself
        // for efficiency
        if (k == a[mid][0]) // checking leftmost element
        {
            return {mid, 0}
//             cout << "Found at (" << mid << ",0)" << endl;
//             return;
        }
 
        if (k == a[mid][m - 1]) // checking rightmost
                                // element
        {
            int t = m - 1;
            return {mid, t}
//             cout << "Found at (" << mid << "," << t << ")" << endl;
//             return;
        }
 
        if (k > a[mid][0] && k < a[mid][m - 1])
        // this means the element
        // must be within this row
        {
            binarySearch(a, n, m, k, mid);
            // we'll apply binary
            // search on this row
            return;
        }
 
        if (k < a[mid][0])
            r = mid - 1;
        if (k > a[mid][m - 1])
            l = mid + 1;
    }
}
 
//Driver Code
int main()
{
    double n = 4; // no. of rows
    double m = 5; // no. of columns
 
    double a[][MAX] = {{0, 6, 8, 9, 11},
                    {20, 22, 28, 29, 31},
                    {36, 38, 50, 61, 63},
                    {64, 66, 100, 122, 128}};
 
    int k = 31; // element to search
 
 
    findRow(a, n, m, k);
     
    return 0;
}


int main()
{
    int r, c;

    // Taking input of number of rows and cols
    scanf("%d %d ",&r, &c);

    int n = r, m = c;

    // Array declaration
    float a[][MAX];

    // Storing inputs of matrix
    for(int i = 0; i<r ;i++) 
    {
        for(int j = 0; j<c; j++)
        {
            scanf("%f ", &arr[i][j]);
        }						 
    
    }
    // Searching element
    float search, smallest, largest;
    scanf("%f", &search);
    smallest = arr[0][0];
    largest = arr[r-1][c-1];

    findRow(a, n, m, k);
    
    return 0;
}