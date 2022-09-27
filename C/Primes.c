#include <stdio.h>
int main()
{
      int a, i, p;
      for(a=2;;a++)
      {
      if(a == 2)
      {p = 1;}
      for(i=2; i < a; i++)
      {
          if(a%i == 0)
          {
              p = 0;
              break;
          }
          p = 1;
      }
      if(p == 1)
      {printf("1");}
      if(p == 0)
      {printf("0");}
      }
      return 0;
}
