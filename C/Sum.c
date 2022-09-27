#include <stdio.h>
#include <math.h>
int main()
{
int t;
scanf("%d", &t);
for(int i=0; i<t; i++){
    unsigned long long int n, r;
    scanf("%llu %llu", &n, &r);
    int m = 100;
    unsigned long long int c_s(unsigned long long int n, unsigned long long int b){
    unsigned long long int s = 0;
    while(n>0){
        s += n%b;
        if(s>=m){
            return m;}
        n = n/b;}
    return s;}
    if(n<=r){
        printf("%llu", n);
        continue;}
    unsigned long long int b, j;
    for(j=2; j<=r; j++){
        unsigned long long int z;
        z = c_s(n, j);
        if(z<m){
            m = z;
            b = j;
            if(m==1){break;}
        }}
    printf("%llu\n", b);
}    return 0;
}
