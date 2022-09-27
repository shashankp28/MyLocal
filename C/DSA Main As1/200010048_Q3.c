#include <stdio.h>
struct node
{
    struct node *next;
    int data;
};
struct node *head1 = NULL;
struct node *head2 = NULL;
void push(int val, int num)
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
int pop(int num)
{
    struct node *head;
    head = num==1 ? head1:head2;
    struct node *del, *delp;
    delp = head;
    del = head->next;
    if(del == NULL)
    {
        int temp = head->data;
        head = NULL;
        free(del);
        if(num==1)
        {
            head1 = head;
        }
        else
        {
            head2 = head;
        }
        return temp;
    }
    while(del->next != NULL)
    {
        del = del->next;
        delp = delp->next;
    }
    delp->next = NULL;
    int temp = del->data;
    free(del);
    if(num==1)
    {
        head1 = head;
    }
    else
    {
        head2 = head;
    }
    return temp;
}
void dequeue()
{
    if(head1==NULL)
    {
        printf("Queue is Empty\n\n");
        return;
    }
    while(head1->next!=NULL)
    {
        push(pop(1), 2);
    }
    int temp = pop(1);
    while(head2!=NULL)
    {
        push(pop(2), 1);
    }
    return;
}
void display()
{
    if(head1==NULL)
    {
        printf("Queue is Empty\n\n");
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
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                push(value, 1);
                break;
            case 2:
                dequeue(1);
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
