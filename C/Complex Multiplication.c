#include <stdio.h>
#include <math.h>
int main()
{
      float a1, b1 ,c1, d1, e, f;
      printf("(a1 + ib1)(c1 + id1)\n");
      printf("a1= ");
      scanf("%f", &a1);
      printf("b1= ");
      scanf("%f", &b1);
      printf("c1= ");
      scanf("%f", &c1);
      printf("d1= ");
      scanf("%f", &d1);
      e = a1*c1 - b1*d1;
      f = a1*d1 + b1*c1;
      if(e == 0)
      {
        if(f == 0)
        {
          printf("0");
        }
        else
        {
            printf("i%.3f", f);
        }
      }

     else
            {
                if(f == 0)
                {
                    printf("%.3f", e);
                }


            else
            {
              printf("(%.3f) + i(%.3f)", e, f);

            }
      }
     return 0;
}

