#include <stdio.h>
struct node
{
    struct node *next;
    int data;
};
struct node *head1 = NULL;
struct node *head2 = NULL;
void enqueue(int val, int num)
{
    struct node *newnode = malloc(sizeof(struct node)), *head;
    newnode->data = val;
    head = num==1 ? head1:head2;
    if(head == NULL)
    {
       head = newnode;
       head->next = NULL;
       if(num==1)
        {
            head1 = head;
        }
        else
        {
            head2 = head;
        }
       return;
    }
    else
    {
        struct node *p;
        p = head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = newnode;
        newnode->next = NULL;
    }
    if(num==1)
    {
        head1 = head;
    }
    else
    {
        head2 = head;
    }
    return;
}
int dequeue(int num)
{
    struct node *head;
    head = num==1 ? head1:head2;
    if(head->next==NULL)
    {
        struct node *p;
        p = head;
        head = NULL;
        free(p);
        if(num==1)
        {
            head1 = head;
        }
        else
        {
            head2 = head;
        }
        return;
    }
    struct node *del;
    del = head;
    int deq = head->data;
    head = head->next;
    if(num==1)
    {
        head1 = head;
    }
    else
    {
        head2 = head;
    }
    free(del);
    return deq;
}
void pop()
{
    if(head1==NULL)
    {
        printf("Stack is Empty\n\n");
        return;
    }
    while(head1->next!=NULL)
    {
        enqueue(dequeue(1), 2);
    }
    int temp = dequeue(1);
    while(head2!=NULL)
    {
        enqueue(head2->data, 1);
        temp = dequeue(2);
    }
    return;
}
void display()
{
    if(head1==NULL)
    {
        printf("Stack is Empty\n\n");
        return;
    }
    struct node *p;
    p = head1;
    while(p->next!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n\n", p->data);
    return;
}
int main()
{
    int option, value, position;
    while(1)
    {
        printf("Please type an option number:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                enqueue(value, 1);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid Option\n\n");
                break;
        }
    }
    return 0;
}
