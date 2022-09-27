#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;

};
int t;
struct node *root = NULL;
void insert(int n)
{
    struct node *newnode = malloc (sizeof (struct node)), *current, *temp;
    newnode->left = NULL;
    newnode->data = n;
    newnode->right = NULL;
    if(root==NULL)
    {
        root = newnode;
        return;
    }
    current = root;
    while(current!=NULL)
    {
        temp = current;
        if(current->data > newnode->data)
        {
             current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if(temp->data > newnode->data)
    {
        temp-> left = newnode;
    }
    else
    {
        temp-> right = newnode;
    }
    return;
}
void inorder(struct node *temp)
{
    if(temp!= NULL)
    {
        inorder(temp->left);
        FILE* g = fopen("bst.txt", "a+");
        if(t!=0){fprintf(g, " ");}
        fprintf(g, "%d", temp->data);
        t++;
        fclose(g);
        inorder(temp->right);
    }
    return;
}
void preorder(struct node *temp)
{
    if(temp!= NULL)
    {
        FILE* g = fopen("bst.txt", "a+");
        if(t!=0){fprintf(g, " ");}
        fprintf(g, "%d", temp->data);
        t++;
        fclose(g);
        preorder(temp->left);
        preorder(temp->right);
    }
    return;
}
void postorder(struct node *temp)
{
    if(temp!= NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        FILE* g = fopen("bst.txt", "a+");
        if(t!=0){fprintf(g, " ");}
        fprintf(g, "%d", temp->data);
        t++;
        fclose(g);
    }
    return;
}
struct node *search(int n)
{
    struct node *temp = root;
    while(temp!=NULL)
    {
        if(n>temp->data)
        {
            temp = temp->right;
            continue;
        }
        if(n<temp->data)
        {
            temp = temp->left;
            continue;
        }
        if(n==temp->data)
        {
            return temp;
        }
    }
    return NULL;
}
struct node *min(struct node *min)
{
    if(min==NULL)
    {
        return NULL;
    }
    while(min->left!=NULL)
    {
        min = min -> left;
    }
    return min;
}
struct node *max(struct node *max)
{
    if(max==NULL)
    {
        return NULL;
    }
    while(max->right!=NULL)
    {
        max = max->right;
    }
    return max;
}
struct node *successor(int n)
{
    struct node *succ = NULL;
    struct node *temp  = root;
    if(!root)
    {
        return NULL;
    }
    while(temp->data != n)
    {
        if(temp->data > n)
        {
            succ = temp;
            temp= temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if(temp && temp->right)
    {
        succ = min(temp->right);
    }
    return succ;
}
struct node *predecessor(int n)
{
    struct node *pred = NULL;
    struct node *temp  = root;
    if(!root)
    {
        return NULL;
    }
    while(temp->data!= n)
    {
        if(temp->data>n)
        {
            temp= temp->left;
        }
        else
        {
            pred = temp;
            temp = temp->right;
        }
    }
    if(temp && temp->left)
    {
        pred = max(temp->left);
    }
    return pred;
}
int main(int argc, char **argv)
{
    if(argc>2 || argc<2)
    {
        printf("INVALID");
        exit(1);
    }
    FILE* f;
    f = fopen(argv[1], "r");
    if(f==NULL)
    {
        printf("FILE NOT FOUND");
        exit(2);
    }
    char c[1000];
    FILE* g = fopen("bst.txt", "w+");
    fclose(g);
    while(fgets(c, 999, f)!= NULL)
    {
        if(strstr(c, "insert"))
        {
            int n = atoi(strstr(c, " "));
            insert(n);
            FILE* g = fopen("bst.txt", "a+");
            fprintf(g, "%d inserted\n", n);
            fclose(g);
        }
        else if(strstr(c, "inorder"))
        {
            t=0;
            inorder(root);
            FILE* g = fopen("bst.txt", "a+");
            fprintf(g, "\n");
            fclose(g);
        }
        else if(strstr(c, "preorder"))
        {
            t=0;
            preorder(root);
            FILE* g = fopen("bst.txt", "a+");
            fprintf(g, "\n");
            fclose(g);
        }
        else if(strstr(c, "postorder"))
        {
            t=0;
            postorder(root);
            FILE* g = fopen("bst.txt", "a+");
            fprintf(g, "\n");
            fclose(g);
        }
        else if(strstr(c, "search"))
        {
            int n = atoi(strstr(c, " "));
            if(!search(n))
            {
                FILE* g = fopen("bst.txt", "a+");
                fprintf(g, "%d not found\n", n);
                fclose(g);
            }
            else
            {
                FILE* g = fopen("bst.txt", "a+");
                fprintf(g, "%d found\n", search(n)->data);
                fclose(g);
            }
        }
        else if(strstr(c, "minimum"))
        {
            if(!min(root))
            {
                FILE* g = fopen("bst.txt", "a+");
                fprintf(g, "\n");
                fclose(g);
            }
            else
            {
                FILE* g = fopen("bst.txt", "a+");
                fprintf(g, "%d\n", min(root)->data);
                fclose(g);
            }
        }
        else if(strstr(c, "maximum"))
        {
             if(!max(root))
            {
                FILE* g = fopen("bst.txt", "a+");
                fprintf(g, "\n");
                fclose(g);
            }
            else
            {
                FILE* g = fopen("bst.txt", "a+");
                fprintf(g, "%d\n", max(root)->data);
                fclose(g);
            }
        }
        else if(strstr(c, "successor"))
        {
            int n = atoi(strstr(c, " "));
            if(!search(n))
            {
                FILE* g = fopen("bst.txt", "a+");
                fprintf(g, "%d does not exist\n", n);
                fclose(g);
            }
            else if(n == max(root)->data)
            {
                FILE* g = fopen("bst.txt", "a+");
                fprintf(g, "successor of %d does not exist\n", n);
                fclose(g);
            }
            else
            {
                FILE* g = fopen("bst.txt", "a+");
                fprintf(g, "%d\n", successor(n)->data);
                fclose(g);
            }
        }
        else if(strstr(c, "predecessor"))
        {
            int n = atoi(strstr(c, " "));
            if(!search(n))
            {
                FILE* g = fopen("bst.txt", "a+");
                fprintf(g, "%d does not exist\n", n);
                fclose(g);
            }
            else if(n == min(root)->data)
            {
                FILE* g = fopen("bst.txt", "a+");
                fprintf(g, "predecessor of %d does not exist\n", n);
                fclose(g);
            }
            else
            {
                FILE* g = fopen("bst.txt", "a+");
                fprintf(g, "%d\n", predecessor(n)->data);
                fclose(g);
            }
        }
        else
        {
            printf("%s: invalid command", c);
        }
    }
    fclose(f);
    return 0;
}
