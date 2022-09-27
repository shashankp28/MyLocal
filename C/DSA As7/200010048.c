#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};
struct adj
{
    struct node *head;
    int in;
    int out;
    int status;
} *list;
struct node *stack = NULL;
struct node *tps = NULL;
struct node *newnode(int n)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;
    return newnode;
}
void enqueue(struct node **head, int n)
{
    struct node *nn = newnode(n);
    if(*head == NULL)
    {
       *head = nn;
       (*head)->next = NULL;
    }
    else
    {
        struct node *p;
        p = *head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = nn;
        nn->next = NULL;
    }
    return;
}
int dequeue(struct node **head)
{
    struct node *del;
    del = *head;
    int temp = del->data;
    *head = (*head)->next;
    free(del);
    return temp;
}
int pop(struct node **head)
{
    struct node *delp = *head, *del = (*head)->next;
    int temp;
    if(del == NULL)
    {
        temp = delp->data;
        *head = NULL;
        free(del);
    }
    else
    {
        while(del->next != NULL)
        {
            del = del->next;
            delp = delp->next;
        }
        temp = del->data;
        delp->next = NULL;
        free(del);
    }
    return temp;
}
void display(struct node *head)
{
    struct node *p = head;
    while(p!=NULL)
    {
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}
void DFS(struct node *head, int value)
{
    struct node *p = head;
    while(p!=NULL )
    {
        if(!(list[p->data].status))
        {
            DFS(list[p->data].head, p->data);
        }
        p = p->next;
    }
    enqueue(&tps, value);
    list[value].status = 1;
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
    list = (struct adj *)malloc(v*sizeof(struct adj));
    for(int i=0; i<v; i++)
    {
        list[i].head = NULL;
        list[i].status = 0;
        list[i].in = 0;
        list[i].out = 0;
    }
    for(int i=0; i<e; i++)
    {
        int n1, n2;
        fscanf(graph, "%d%d", &n1, &n2);
        enqueue(&(list[n1].head), n2);
        list[n1].out++;
        list[n2].in++;
    }
    fclose(graph);
    int inn=0, iso=0;
    for(int i=0; i<v; i++)
    {
        if(list[i].out!=0 && list[i].in==0)
        {
            inn++;
        }
        if(list[i].out==0 && list[i].in==0)
        {
            iso++;
        }
    }
    for(int i=0; i<v; i++)
    {
        if(!(list[i].in) && list[i].out && !(list[i].status))
        {
            DFS(list[i].head, i);
        }
        if(!(list[i].in || list[i].out || list[i].status))
        {
            enqueue(&tps, i);
            list[i].status = 1;
        }
    }
    FILE *f;
    f = fopen("ts.txt", "w+");
    while(tps!=NULL)
    {
        fprintf(f, "%d\n", pop(&tps));
    }
    fclose(f);
    return 0;
}
