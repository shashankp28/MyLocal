#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
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
    int n=0, sum=0, min, max, i;
    char c[1000];
    while(fgets(c, 999, f)!= NULL)
    {
        i = atoi(c);
        n++;
        sum+=i;
        if(n==1)
        {
            min = i;
            max = i;
        }
        else
        {
            min = min<=i ? min : i;
            max = max>=i ? max : i;
        }
    }
    if(n==0)
    {
        printf("NO NUMBERS PRESENT");
        exit(3);
    }
    FILE* g;
    g = fopen("output.txt", "w+");
    fprintf(g, "%d\n%d\n%d\n%d\n%.2f\n", n, min, max, sum, (float)sum/n);
    fclose(f);
    fclose(g);
    return 0;
}
