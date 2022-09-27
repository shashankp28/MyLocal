#include<stdio.h>
#include<stdlib.h>

FILE* fo=NULL;
FILE* fo2=NULL;

struct Node{
	struct Node* next;
	int data;
};
struct lkls{
	struct Node* head;
}; 
struct mp_col{
	int col;
};
struct Stack{
	struct Node* head;
	struct Node* tail;
};
struct Node* create(int data)
{
	struct Node* n=(struct Node*)malloc(sizeof(struct Node));
	n->data=data;
	n->next=NULL;
	return n;
}
struct Node* insert_b(struct Node* head,int data)
{
	struct Node* n=create(data);
	if(head==NULL){
		return n;
	}
	n->next=head;
	return n;
}
void Enqueue(struct Node** head,int data)
{
	struct Node* nw=create(data);
	struct Node* temp=*head;
	if(*head==NULL){
		*head=nw;
		return;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=nw;
}
struct Node* insert_etail(struct Node* tail,int data)
{
	struct Node* n=create(data);
	tail->next=n;
	return n;
}
struct Node* insert_e(struct Node* head,int data)
{
	struct Node* n=create(data);
	struct Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
	return n;
	//return head;
}
struct Node* insert_p(struct Node* head,int pos,int data)
{
	struct Node* n=create(data);
	struct Node* temp=head;
	for(int i=1;i<pos && temp->next!=NULL;i++){
		temp=temp->next;
	}
	n->next=temp->next;
	temp->next=n;
	return head;
}

int del_b(struct Node** head)
{
	struct Node* temp=*head;
	if(temp==NULL){
		printf("\nunderflow..\n");
		return -1;
	}
	int pv= temp->data;
	*head=temp->next;
	//free(temp);
	return pv;
}

struct Node* del_e(struct Node* head)
{
	struct Node* temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	struct Node* p=temp->next;
	temp->next=NULL;
	free(p);
	return temp;
}

struct Node* del_p(struct Node* head,int pos)
{
	struct Node* temp=head;
	for(int i=1;i<pos && temp->next!=NULL;i++){
		temp=temp->next;
	}
	struct Node* p=temp->next;
	temp->next=temp->next->next;
	free(p);
	return head;
}
void print(struct Node* head)
{
	struct Node* temp=head;
	while(temp->next!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
//	n->prev=NULL;
}

////------------------------------stack------------------------
struct Stack createS()
{
	struct Stack s;
	s.head=NULL;
	s.tail=NULL;
	return s;
}

void Push(struct Stack* s,int d){
	s->head=insert_b(s->head,d);
}

int Pop(struct Stack* s){
	int t=del_b(&(s->head));
	return t;
}
void printS(struct Stack* s){
	print(s->head);
}
int isStackEmpty(struct Node* head){
	if(head==NULL){
		return 1;
	}
	return 0;
}
void dfs(int vtx,int edg) //adgencylist
{
	struct lkls* lk=(struct lkls *)malloc(vtx*sizeof(struct lkls));
	struct mp_col vtc[vtx];
	int dprev[vtx];
	int arr[vtx];
	for(int i=0;i<vtx;i++){
		lk[i].head=NULL;
		dprev[i]=0;
		vtc[i].col=0;
	}
	int x=-2,y=-2,cnt=0;
	while(cnt<edg && fscanf(fo,"%d %d",&x,&y)!=EOF){
			Enqueue(&lk[x].head,y);
			dprev[y]+=1;
		cnt++;
	}
	cnt=0;
	int number;
	while(fscanf(fo2,"%d",&number)!=EOF){
		arr[number]=cnt;
		cnt++;
	}
	int count_err=0;
	for(int k=0;k<vtx;k++){
	    struct Node * temp=lk[k].head;
		while(temp!=NULL){
			if(arr[temp->data]<arr[k])
			{
				count_err++;
				printf(" k->%d : data->%d \n",k,temp->data);
			}
			temp=temp->next;
		}	
	}
	printf(" total error %d ",count_err);
}


int main(int argc,char *argv[])
{
	//check checker input.txt output.txt 
	if(argc!=3){
		printf("incorrect Number of arguments");
		exit(0);
	}
	fo=fopen(argv[1],"r");
	fo2=fopen(argv[2],"r");
	if(!fo || !fo2) {
		printf("files do not exist or error reading it");
		exit(0);
	}
	char ch[100];
	int vtx=0,edg=0;
	if(fscanf(fo,"%d %d",&vtx,&edg)){
	}else{
		printf("unable to read");
		exit(0);
	}
	struct Stack s1=createS();
	dfs(vtx,edg);
	fclose(fo);
	fclose(fo2);
	return 0;
	
}
