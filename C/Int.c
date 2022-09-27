#include <stdio.h>
#include <math.h>
int main()
{
    int i=1, j=50000;
    float z = 0;
    float a, b, c, d, e, f, p, q, r, s, t;
    printf("Integrate px^4 + qx^3 + rx^2 + sx + t from 'a' to 'b'\n");
    printf("\np=");
    scanf("%f", &p);
    printf("\nq=");
    scanf("%f", &q);
    printf("\nr=");
    scanf("%f", &r);
    printf("\ns=");
    scanf("%f", &s);
    printf("\nt=");
    scanf("%f", &t);
    printf("\nupper limit b =");
    scanf("%f", &b);
    printf("\nupper limit a =");
    scanf("%f", &a);
    e = (b-a)/j;
    while (i<=j)
        {
            f = a + i*e;
            c = z;
            z = z + e*((p*f*f*f*f)+(q*f*f*f)+(r*f*f)+(s*f)+t) ;
            d = c - z;
            if (d = 0)
                      {
                          i = i + 50000;
                      }
            else
                      { 
                          i = i + 1;
                      }
            
        }  
     printf("Infnite sum = %.3f", z);
    return 0;
}