#include <stdio.h>
int main()
{
     char a[10], t, s;
     int i, n[3], Q, j, k, l;
     scanf("%s", &a);
     scanf("%d", &Q);
     for(i=1; i<=Q; i++)
     {
     for(j=0; j<3; j++)
     {
         scanf("%d", &n[j]);
     }
     switch(n[0])
     {
         case 1:
         t = a[n[1]-1];
         a[n[1]-1] = a[n[2]-1];
         a[n[2]-1] = t;
         break;
         case 2:
         for(k=0; k<=4; k++)
     {
        s = a[9-k];
        a[9-k] = a[k];
        a[k] = s;
     }
        break;
     }
     }
     for(i=0; i<=9; i++)
     {
          printf("%c", a[i]);
     }
    return 0;
}

