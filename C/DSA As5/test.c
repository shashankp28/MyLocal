#include <stdio.h>
#include <stdlib.h>

#define size 500

struct node
{
    char *data;
    struct node *next;
};

struct node *chain[size];

int check_index(int hash_index, int m)
{
    if (chain[hash_index] == 0)
    {
        return hash_index;
    }
    else
    {
        while (chain[hash_index] != 0)
        {
            //  printf("changed from %d to \n", hash_index);
            hash_index = hash_index + 1;
            hash_index = hash_index % m;
        }
        // printf("%d\n", hash_index);

        return hash_index;
    }
}
void init()
{
    int i;
    for (i = 0; i < size; i++) {
        chain[i] = NULL;
    }
}

void insert(char *value , int key)
{
    //create a newnode with value
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
   // int key = value % size;

    //check if chain[key] is empty
    if (chain[key] == NULL) {
        chain[key] = newNode;
    }
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = chain[key];
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void print()
{
    int i;

    for (i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
      //  printf("chain[%d]-->", i);
        while (temp)
        {
            printf("%s", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    //init array of list to NULL
    init();
    int m = 25000;
    char line[50];
    FILE *query = fopen("query1.txt" /*argv[3]*/, "r");

    while (fgets(line, 50, query) != NULL)
    {
        int i = 0, sum = 0;
        int length = strlen(line);
        for (int i = 0; i < length; i++)
        {
            sum += (int)line[i];
            i++;
        }
        int index = sum % m;
        index = check_index(index, m);

        //printf("index checked %d\n", index);
        insert(line, index);
    }
    fclose(query);
    // insert(7);
    // insert(0);
    // insert(3);
    // insert(10);
    // insert(4);
    // insert(5);

    print();

    return 0;
}