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
    int status;
    int dist;
};
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
    int i=0, v, e, d=-1;
    fscanf(graph, "%d%d", &v, &e);
    struct adj list[v];
    for(int i=0; i<v; i++)
    {
        list[i].head = NULL;
        list[i].status = 0;
        list[i].dist = d;
    }
    for(int i=0; i<e; i++)
    {
        int n1, n2;
        fscanf(graph, "%d%d", &n1, &n2);
        enqueue(&(list[n1].head), n2);
        enqueue(&(list[n2].head), n1);
    }
    fclose(graph);
    struct node *queue = newnode(0);
    list[0].dist = 0;
    list[0].status = 1;
    while(queue!=NULL)
    {
        int temp = dequeue(&queue);
        struct node *p = list[temp].head;
        list[temp].status = 2;
        int temp_dist = list[temp].dist;
        while(p!=NULL)
        {
            if(list[p->data].status == 0)
            {
                enqueue(&(queue), p->data);
                list[p->data].dist = temp_dist+1;
                list[p->data].status = 1;
            }
            p = p->next;
        }
    }
    FILE *f = fopen("sd.txt", "w+");
    for(int i=0; i<v; i++)
    {
        fprintf(f, "%d\n", list[i].dist);
    }
    fclose(f);
    return 0;
}
