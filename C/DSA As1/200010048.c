#include <stdio.h>
int top[3] = {-1, -1, -1}, n, **tower, temp;
char tower_name[3] = {'A', 'B', 'C'};
static FILE *f;
void push(int disk, int tower_no) // PUSH FUNCTION
{
    if(top[tower_no]!=n-1)
    {
        top[tower_no]++;
        tower[tower_no][top[tower_no]] = disk;
        fprintf(f, "Push disk %d to Stack %c\n", disk, tower_name[tower_no]);
        return;
    }
    else
    {
        printf("Stackoverflow!\n");    //STACKOVERFLOW
        return;
    }
}
void pop(int tower_no)   // POP FUNCTION
{
    if(top[tower_no]!=-1)
    {
        temp = tower[tower_no][top[tower_no]];
        fprintf(f, "Pop disk %d from Stack %c\n", tower[tower_no][top[tower_no]], tower_name[tower_no]);
        tower[tower_no][top[tower_no]] = -1;
        top[tower_no]--;
        return;
    }
    else
    {
        printf("Stackunderflow!\n");      // STACKUNDERFLOW
        return;
    }
}
void check()      // CHECK IF GAME IS OVER
{
    if(top[2]==n-1)
    {
        fclose(f);
        exit(0);
    }
    return;
}
void AB()        // THREE SWITCHING FUNCTIONS
{
    if(top[0]>=0 && (top[1]==-1 || tower[1][top[1]]>tower[0][top[0]]))
    {
        pop(0);
        push(temp, 1);
    }
    else
    {
        pop(1);
        push(temp, 0);
    }
    check();
    return;
}
void BC()
{
    if(top[1]>=0 && (top[2]==-1 || tower[2][top[2]]>tower[1][top[1]]))
    {
        pop(1);
        push(temp, 2);
    }

    else
    {
        pop(2);
        push(temp, 1);
    }
    check();
    return;
}
void AC()
{
    if(top[0]>=0 && (top[2]==-1 || tower[2][top[2]]>tower[0][top[0]]))
    {
        pop(0);
        push(temp, 2);
    }
    else
    {
        pop(2);
        push(temp, 0);
    }
    check();
    return;
}
int main(int argc, char **argv)
{
    int i, j;
    if(argc==1 || argc>2 || atoi(argv[1])<1)
    {
        printf("INVALID");
        exit(1);
    }
    n = atoi(argv[1]);
    tower = (int **)malloc(3*sizeof(int*));
    for(i=0; i<3; i++)
    {
        tower[i] = (int *)malloc(n*sizeof(int));
    }
    f = fopen("toh.txt", "w+");
    for(i=n-1; i>-1; i--)
    {
        push(i+1, 0);
    }
    while(1)
    {
        if(n%2==0)
        {
            AB();
            AC();
            BC();
        }
        else
        {
            AC();
            AB();
            BC();
        }
    }
    return 0;
}
