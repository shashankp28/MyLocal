#include <stdio.h>
struct node
{
    struct node *next;
    int data;
};
struct node *head = NULL;
void ins_begin(int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    if(head == NULL)
    {
        head = newnode;
        head->next = head;
        return;
    }
    else
    {
        struct node *p;
        p = head;
        while(p->next != head)
        {
            p = p->next;
        }
        newnode->next = head;
        head = newnode;
        p->next = head;
    }
    return;
}
void ins_end(int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    if(head == NULL)
    {
       ins_begin(val);
       return;
    }
    else
    {
        struct node *p;
        p = head;
        while(p->next != head)
        {
            p = p->next;
        }
        p->next = newnode;
        newnode->next = head;
    }
    return;
}
void ins_pos(int val, int pos)
{
    if(pos==0)
    {
        ins_begin(val);
        return;
    }
    if(pos<0)
    {
        printf("Invalid Position\n\n");
        return;
    }
    if(head == NULL)
    {
        printf("Invalid Position\n\n");
        return;
    }
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    struct node *p;
    p = head;
    for(int i=0; i<pos-1; i++)
    {
        if(p->next == head)
        {
            printf("Invalid Position\n\n");
            return;
        }
        p = p->next;
    }
    newnode->next = p->next;
    p->next = newnode;
    return;
}
void del_begin()
{
    if(head==NULL)
    {
        printf("List is Empty\n\n");
        return;
    }
    if(head->next==head)
    {
        struct node *p;
        p = head;
        head = NULL;
        free(p);
        return;
    }
    struct node *p, *del;
    p = head;
    del = head;
    while(p->next != head)
    {
        p = p->next;
    }
    head = head->next;
    p->next = head;
    free(del);
    return;
}
void del_end()
{
    if(head==NULL)
    {
        printf("List is Empty!\n\n");
        return;
    }
    if(head->next==head)
    {
        del_begin();
        return;
    }
    struct node *p, *del, *delp;
    delp = head;
    del = head->next;
    while(del->next != head)
    {
        del = del->next;
        delp = delp->next;
    }
    delp->next = head;
    free(del);
    return;
}
void del_pos(int pos)
{
    if(head==NULL)
    {
        printf("List is Empty\n\n");
        return;
    }
    if(pos==0)
    {
        del_begin();
        return;
    }
    struct node *p, *del, *delp;
    delp = head;
    del = head->next;
    for(int i=0; i<pos-1; i++)
    {
        if(del->next==head)
        {
            printf("Invalid Position\n\n");
            return;
        }
        del = del->next;
        delp = delp->next;
    }
    delp->next = del->next;
    free(del);
    return;
}
void display()
{
    if(head==NULL)
    {
        printf("List is Empty\n\n");
        return;
    }
    struct node *p;
    p = head;
    while(p->next!=head)
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
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at the given position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from the given position\n");
        printf("7. Display\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                ins_begin(value);
                break;
            case 2:
                printf("Value: ");
                scanf("%d", &value);
                ins_end(value);
                break;
            case 3:
                printf("Value: ");
                scanf("%d", &value);
                printf("Postion: ");
                scanf("%d", &position);
                ins_pos(value, position);
                break;
            case 4:
                del_begin();
                break;
            case 5:
                del_end();
                break;
            case 6:
                printf("Postion: ");
                scanf("%d", &position);
                del_pos(position);
                break;
            case 7:
                display();
                break;
            default:
                printf("Invalid Option\n\n");
                break;
        }
    }
    return 0;
}
