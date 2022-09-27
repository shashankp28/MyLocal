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
int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
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
int largestComponentSize(int* nums, int numsSize)
{
        int ans=0;
        int v=numsSize, d=-1;
        struct adj list[v];
        for(int i=0; i<v; i++)
        {
            list[i].head = NULL;
            list[i].status = 0;
            list[i].dist = d;
        }
        for(int i=0; i<v-1; i++)
        {
            for(int j=i+1; j<v; j++)
            {
                if(gcd(nums[i], nums[j])!=1)
                {
                    enqueue(&(list[i].head), j);
                    enqueue(&(list[j].head), i);
                }
            }
        }
        int arr[v];
        for(int i=0; i<v; i++) arr[i]=i;
        while(1)
        {
            int j=-1;
            for(int i=0; i<v; i++)
            {
                if(arr[i]!=-1)
                {
                    j=i;
                    break;
                }
            }
            if(j==-1) break;
            struct node *queue = newnode(j);
            int count=1;
            list[j].dist = 0;
            list[j].status = 1;
            arr[j] = -1;
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
                        arr[p->data] = -1;
                        count++;
                    }
                    p = p->next;
                }
            }
            for(int i=0; i<v; i++)
            {
                list[i].status = 0;
                list[i].dist = d;
            }
            if(count>ans) ans=count;
        }
        return ans;
}
int main()
{
    int n;
    printf("n= ");
    scanf("%d", &n);
    int a[n];
    printf("array= ");
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    printf("%d", largestComponentSize(a, n));
    return 0;
}