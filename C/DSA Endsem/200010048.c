#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct node
{
    struct node *next;
    int data;
    int weight;
};
struct adj
{
    struct node *head;
    int status;
    float dist;
} *list;
struct node *newnode(int n, int w)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = n;
    newnode->weight = w;
    newnode->next = NULL;
    return newnode;
}
void ins_beg(struct node **head, int n, int w)
{
    struct node *nn = newnode(n, w);
    nn->next = *head;
    *head = nn;
    return;
}
int get_min(int v)
{
    float t = INFINITY;
    int min=-1;
    for(int i=0; i<v; i++)
    {
        if(list[i].dist<t && list[i].status==0)
        {
            t = list[i].dist;
            min = i;
        }
    }
    return min;
}
void display(struct node *head)
{
    struct node *p = head;
    while(p!=NULL)
    {
        printf("(%d: %d) ", p->data, p->weight);
        p = p->next;
    }
    printf("\n");
    return;
}
int main(int argc, char **argv)
{
    if(argc>3 || argc<3)
    {
        printf("Inavlid Input!");
        exit(1);
    }
    FILE* f;
    f = fopen(argv[1], "r");
    if(f==NULL)
    {
        printf("FILE NOT FOUND");
        exit(2);
    }
    int e=0, v=0, s=atoi(argv[2]);
    int x, y, w;
    while(fscanf(f, "%d%d%d", &x, &y, &w)!=EOF)
    {
        e++;
        if(x>v || y>v)
        {
            v = x>y ? x : y;
        }
    }
    v++;
    fclose(f);
    list = (struct adj *)malloc(v*sizeof(struct adj));
    for(int i=0; i<v; i++)
    {
        list[i].head = NULL;
        list[i].status = 0;
        list[i].dist = INFINITY;
    }
    list[s].dist = 0;
    f = fopen(argv[1], "r");
    for(int i=0; i<e; i++)
    {
        int n1, n2;
        fscanf(f, "%d%d%d", &n1, &n2, &w);
        ins_beg(&(list[n1].head), n2, w);
    }
    fclose(f);
    int z=0;
    while(z<v)
    {
        int q = get_min(v);
        if(q==-1){break;}
        struct node *p = list[q].head;
        while(p!=NULL)
        {
            if(list[p->data].status==0)
            {
                if(list[p->data].dist > list[q].dist + p->weight)
                {
                    list[p->data].dist = list[q].dist + p->weight;
                }
            }
            p = p->next;
        }
        list[q].status = 1;
        z++;
    }
    f = fopen("dijkstra.txt", "w+");
    for(int i=0; i<v; i++)
    {
        fprintf(f, "%d ", i);
        (list[i].dist == INFINITY ? fprintf(f, "-1\n") : fprintf(f, "%d\n", (int)list[i].dist));
    }
    return 0;
    fclose(f);
}
