#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

void chk(struct node *);
void qu(struct node* );
void cop(struct node*,struct node*);
void show(struct node*);

int ans[3][3] = {1,2,3,8,0,4,7,6,5};


struct node{
int qu[3][3];
struct node *next;
}*start=NULL,*curr=NULL;

void main()
{

	clrscr();
	int ini[3][3] ={1,2,3,4,5,0,7,8,6};
	struct node *yuk;
	yuk = (struct node*)malloc(sizeof(struct node));
	for(int q =0;q<3;q++)
		for(int w =0 ;w<3;w++)
			cin>>yuk->qu[q][w];

			//yuk->qu[3][3] = {1,2,3,4,5,0,7,8,6};
	yuk->next = NULL;
	start = yuk;
	curr = start;
	clrscr();
	for(int i = 0; ;i++)
	{
		show(curr);
		chk(curr);
		qu(curr);
		curr = curr->next;

	}
}

void show(struct node * curr)
{
	for(int i=0;i<3;i++)
	{
	for(int j= 0;j<3;j++)
	{
		cout<<curr->qu[i][j]<<"\t";
	}
	cout<<"\n";
	}
	cout<<"\n\n";
}

void chk(struct node *curr)
{
	int temp = 0;
	for(int i = 0;i<3;i++)
	{
	for(int j =0;j<3;j++)
	{
		if(curr->qu[i][j]!=ans[i][j])
		{
			temp = 1;
			break;
		}
	}
	if(temp == 1)
		break;
	}
	if(temp==0)
	{
		cout<<"Reached";
		getch();
		exit(1);
	}
}

void qu(struct node *n)
{
	struct node *temp,*temp1;
	int t,ch=0;
	temp1 = n;
	temp = (struct node*)malloc(sizeof(struct node));
	cop(temp,n);
	temp->next=NULL;
	for(int i = 0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(temp->qu[i][j] == 0 && j-1>=0)
			{
				t=temp->qu[i][j];
				temp->qu[i][j] = temp->qu[i][j-1];
				temp->qu[i][j-1] = t;
				ch = 1;
				break;
			}
		}
		if(ch==1)
		break;
	}
	if(ch == 1)
	{
		temp1->next = temp;
		temp1 = temp1->next;
	}
	ch = 0;
	cop(temp,n);
	temp->next = NULL;

	for(i = 0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(temp->qu[i][j] == 0 && j+1<3)
			{
				t=temp->qu[i][j];
				temp->qu[i][j] = temp->qu[i][j+1];
				temp->qu[i][j+1] = t;
				ch = 1;
				break;
			}
		}
		if(ch==1)
		break;
	}
	if(ch == 1)
	{
		temp = temp1->next;
		temp1 = temp1->next;
	}

	ch = 0;
	cop(temp,n);
	temp->next = NULL;

	for(i = 0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if((temp->qu[i][j] == 0) && (i+1<3))
			{
				t=temp->qu[i][j];
				temp->qu[i][j] = temp->qu[i+1][j];
				temp->qu[i+1][j] = t;
				ch = 1;
				break;
			}
		}
		if(ch==1)
		break;
	}
	if(ch == 1)
	{
		temp = temp1->next;
		temp1 = temp1->next;
	}

	ch = 0;
	cop(temp,n);
	temp->next = NULL;

	for(i = 0;i<3;i++)
	{

		for(int j=0;j<3;j++)
		{
			if(temp->qu[i][j] == 0 && i-1>=0)
			{
				t=temp->qu[i][j];
				temp->qu[i][j] = temp->qu[i-1][j];
				temp->qu[i-1][j] = t;
				ch = 1;
				break;
			}
		}
		if(ch==1)
		break;
	}
	if(ch == 1)
	{
		temp = temp1->next;
		temp1 = temp1->next;
	}

}

void cop(struct node* temp,struct node* n)
{
	for(int i =0;i<3;i++)
	{
	for(int j=0;j<3;j++)
	{

		temp->qu[i][j]=n->qu[i][j];
	}
	}
}