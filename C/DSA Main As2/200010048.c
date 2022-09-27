#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    struct node *next;
    int weight;
    int begin;
    int end;
};
float pinf = INFINITY;
struct node *edge = NULL;
struct node *newnode(int w, int b, int e)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->weight = w;
    newnode->begin = b;
    newnode->end = e;
    newnode->next = NULL;
    return newnode;
}
void ins_beg(struct node **head, int w, int b, int e)
{
    struct node *nn = newnode(w, b, e);
    nn->next = *head;
    *head = nn;
    return;
}
void BellmanFord(float arr[], int v)
{
    for(int i=1; i<v; i++)
    {
        struct node *p = edge;
        while(p!=NULL)
        {
            if(arr[p->end] > arr[p->begin] + p->weight)
            {
                arr[p->end] = arr[p->begin] + p->weight;
            }
            p = p->next;
        }
    }
    return;
}
void display(struct node *head)
{
    struct node *p = head;
    while(p!=NULL)
    {
        printf("%d, %d, %d\n", p->weight, p->begin, p->end);
        p = p->next;
    }
    return;
}
int main(int argc, char **argv)
{
   if(argc>2 || argc<2)
    {
        printf("INVALID COMMAND LINE ARGUMENT!");
        exit(1);
    }
    FILE *graph;
    graph = fopen(argv[1], "r");
    if(graph==NULL)
    {
        printf("FILE NOT FOUND");
        exit(2);
    }
    int i=0, v, e;
    fscanf(graph, "%d%d", &v, &e);
    float list[v], temp[v];
    for(int i=0; i<v; i++)
    {
        list[i] = pinf;
    }
    list[0] = 0;
    for(int i=0; i<e; i++)
    {
        int n1, n2, w;
        fscanf(graph, "%d%d%d", &n1, &n2, &w);
        ins_beg(&edge, w, n1, n2);
    }
    fclose(graph);
    BellmanFord(list, v);
    for(int i=0; i<v; i++)
    {
        temp[i] = list[i];
    }
    BellmanFord(temp, v);
    FILE *f;
    f = fopen("sd.txt", "w+");
    for(int i=0; i<v; i++)
    {
        if(list[i]==pinf)
        {
            fprintf(f, "%d +inf\n", i);
        }
        else if(list[i]>temp[i])
        {
            fprintf(f, "%d -inf\n", i);
        }
        else
        {
            fprintf(f, "%d %d\n", i, (int)list[i]);
        }
    }
    fclose(f);
    return 0;
}
