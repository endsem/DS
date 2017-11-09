#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *lcptr;
	int data;
	struct node *rcptr;
};

struct node *rptr=NULL;
int c=0,f=0;

struct node *insert(struct node *rptr,int x)
{
	if(rptr==NULL)
	{
		rptr=(struct node*)malloc(sizeof(struct node));
		rptr->data=x;
		rptr->lcptr=rptr->rcptr=NULL;
	}
	else
	{
		if(x<rptr->data)
			rptr->lcptr=insert(rptr->lcptr,x);
		else
			rptr->rcptr=insert(rptr->rcptr,x);
	}

	return rptr;
}

struct node *inorder_successor(struct node *rptr)
{
	struct node *t=rptr->rcptr;
	while(t->lcptr!=NULL)
		t=t->lcptr;
	return t;
}

struct node *delete(struct node *rptr,int x)
{
	if(rptr==NULL)
		return rptr;
	else
	{
		if(x<rptr->data)
			rptr->lcptr=delete(rptr->lcptr,x);
		else if(x>rptr->data)
			rptr->rcptr=delete(rptr->rcptr,x);
		else
		{
			if(rptr->lcptr==NULL)
			{
				struct node *temp=rptr->rcptr;
				free(rptr);
				f=1;
				return temp;
			}

			else if(rptr->rcptr==NULL)
			{
				struct node *temp=rptr->lcptr;
				free(rptr);
				f=1;
				return temp;
			}
			else
			{
				struct node *temp=inorder_successor(rptr);
				rptr->data=temp->data;
				rptr->rcptr=delete(rptr->rcptr,temp->data);
			}
		}
	}

	return rptr;
}

void inorder(struct node *rptr)
{
	if(rptr!=NULL)
	{
		inorder(rptr->lcptr);
		printf("%d ",rptr->data);
		inorder(rptr->rcptr);
	}
}

void preorder(struct node *rptr)
{
	if(rptr!=NULL)
	{
		printf("%d ",rptr->data);
		preorder(rptr->lcptr);
		preorder(rptr->rcptr);
	}
}

void postorder(struct node *rptr)
{
	if(rptr!=NULL)
	{
		postorder(rptr->lcptr);
		postorder(rptr->rcptr);
		printf("%d ",rptr->data);
	}
}

void search(int x)
{
	struct node *t=rptr;
	int f=0;
	while(t!=NULL)
	{
		if(x<t->data)
			t=t->lcptr;
		else if(x>t->data)
			t=t->rcptr;
		else
		{
			f=1;
			break;
		}
	}
	if(f==1)
		printf("%d is found in BST\n",x);
	else
		printf("%d is not found in BST\n",x);
}

int height(struct node *rptr)
{
	if(rptr==NULL)
		return -1;
	else
	{
		int LH=height(rptr->lcptr);
		int RH=height(rptr->rcptr);
		if(LH>RH)
			return LH+1;
		else
			return RH+1;
	}
}

void count(struct node *rptr)
{
	if(rptr!=NULL)
	{
		count(rptr->lcptr);
		count(rptr->rcptr);
		c++;
	}
}

int main()
{
	int t;
	while(1)
	{
		printf("1.Insert\n2.Delete\n3.Search\n4.Height\n5.Count\n6.Inorder\n7.Preorder\n8.Postorder\n9.Exit\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 :
			{
				int x;
				printf("Enter integer to be inserted\n");
				scanf("%d",&x);
				rptr=insert(rptr,x);
				printf("%d is successfully inserted in BST\n",x);
			}
			break;

			case 2 :
			{
				int x;
				printf("Enter integer to be deleted\n");
				scanf("%d",&x);
				f=0;
				rptr=delete(rptr,x);
				if(f==1)
					printf("%d is successfully deleted from BST\n",x);
				else
					printf("%d is not found in BST.Hence,cannot be deleted\n",x);
			}
			break;

			case 3 :
			{
				int x;
				printf("Enter integer to be searched\n");
				scanf("%d",&x);
				search(x);
			}
			break;

			case 4 :
			{
				printf("Height of BST: %d\n",height(rptr));
			}
			break;

			case 5 :
			{
				c=0;
				count(rptr);
				printf("Number of nodes present BST:%d\n",c);
			}
			break;

			case 6 :
			{
				printf("Inorder sequence:-\n");
				inorder(rptr);
				printf("\n");
			}
			break;

			case 7 :
			{
				printf("Preorder sequence:-\n");
				preorder(rptr);
				printf("\n");
			}
			break;

			case 8 :
			{
				printf("Postorder sequence:-\n");
				postorder(rptr);
				printf("\n");
			}
			break;

			case 9 : return 0;
			break;

			default : {}


		}
	}
}