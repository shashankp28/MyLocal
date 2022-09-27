#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    char data[100];
};
void sort(char *string, int n)
{
    for (int i = 0; i < n-1; i++)
    {
      for (int j = i+1; j < n; j++)
      {
         if (string[i] > string[j])
         {
            int temp = string[i];
            string[i] = string[j];
            string[j] = temp;
         }
      }
   }
   return;
}
int check(char *str1, char *str2)
{
    sort(str1, strlen(str1));
    sort(str2, strlen(str2));
    return strcmp(str1, str2);
}
struct node *insert(struct node *head, char *str)
{
    struct node *newnode = malloc(sizeof(struct node));
    strcpy(newnode->data, str);
    if(head == NULL)
    {
        head = newnode;
        head->next = NULL;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    return head;
}
void display(struct node *head, char *str)
{
    int t=0;
    FILE *anagrams = fopen("anagrams.txt", "a+");
    while(head!=NULL)
    {
        char str1[100], str2[100];
        strcpy(str1, str);
        strcpy(str2, head->data);
        if(!check(str1, str2))
        {
            if(t!=0)
            {
                fprintf(anagrams, " ");
            }
            t++;
            fprintf(anagrams, "%s", head->data);
        }
        head = head->next;
    }
    fprintf(anagrams, "\n");
    fclose(anagrams);
    return;
}
int main(int argc, char **argv)
{
    if(argc>4 || argc<4)
    {
        printf("INVALID COMMAND LINE ARGUMENT!");
        exit(1);
    }
    FILE *words, *query, *anagrams;
    words = fopen(argv[1], "r");
    query = fopen(argv[3], "r");
    anagrams = fopen("anagrams.txt", "w+");
    fclose(anagrams);
    if(words==NULL || query==NULL)
    {
        printf("FILE NOT FOUND");
        exit(2);
    }
    int m = atoi(argv[2]);
    char c[100];
    struct node **hash = malloc(m*sizeof(struct node *));
    for(int i=0; i<m; i++)
    {
        hash[i] = NULL;
    }
    while(fgets(c, 99, words)!= NULL)
    {
        int sum=0;
        if(c[strlen(c)-1]=='\n')
        {
            c[strlen(c)-1] = '\0';
        }
        for(int i=0; i<strlen(c); i++)
        {
            sum += (int)c[i];
        }
        hash[sum%m] = insert(hash[sum%m], c);
    }
    fclose(words);
    while(fgets(c, 99, query)!= NULL)
    {
        int sum=0;
        if(c[strlen(c)-1]=='\n')
        {
            c[strlen(c)-1] = '\0';
        }
        for(int i=0; i<strlen(c); i++)
        {
            sum += (int)c[i];
        }
        display(hash[sum%m], c);
    }
    return 0;
}
