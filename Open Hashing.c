

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int roll;
	char name[30];
	int marks;
	struct node *link;
};

struct node *head[10];

void insert()
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter Roll Number\n");
	scanf("%d",&temp->roll);
	printf("Enter Name\n");
	scanf("%s",temp->name);
	printf("Enter Marks\n");
	scanf("%d",&temp->marks);
	int arr_index=(temp->roll)%10;

	temp->link=NULL;

	if(head[arr_index]==NULL)
	{
		head[arr_index]=temp;
	}
	else
	{
		struct node *t=head[arr_index];
		while(t->link!=NULL)
		{
			t=t->link;
		}
		t->link=temp;
	}
	printf("Record is successfully inserted with Roll Number %d at array index %d\n",temp->roll,arr_index);

}

void delete()
{
	int roll;
	printf("Enter Roll Number of the record to be deleted\n");
	scanf("%d",&roll);
	int arr_index=roll%10;

	struct node *t=head[arr_index];
	
	if(t==NULL)
	{
		printf("Entered Roll Number not found\n");
		return;
	}

	if(t->roll==roll)
	{
		head[arr_index]=t->link;
		printf("Record with the Roll Number %d is deleted\n",roll);
		return;
	}
	t=t->link;

	struct node *prev=head[arr_index];

	while(t!=NULL)
	{
		if(roll==t->roll)
		{
			prev->link=t->link;
			printf("Record with the Roll Number %d is deleted\n",roll);
			return;
		}

		prev=t;
		t=t->link;
	}
	printf("Entered Roll Number not found\n");
}

void search()
{
	int roll;
	printf("Enter Roll Number to be searched for\n");
	scanf("%d",&roll);
	int arr_index=roll%10;

	struct node *t=head[arr_index];

	while(t!=NULL)
	{
		if(roll==t->roll)
		{
			printf("Roll No: %d, Name: %s, Marks: %d\n",t->roll,t->name,t->marks);
			return;
		}

		t=t->link;
	}
	printf("Entered Roll Number not found\n");
}

void display()
{
	struct node *t;
	int i;
	for(i=0;i<10;i++)
	{
		t=head[i];
		if(t==NULL)
			continue;
		else
		{
			while(t!=NULL)
			{
				printf("Roll No: %d, Name: %s, Marks: %d\n",t->roll,t->name,t->marks);
				t=t->link;
			}
		}
	}
}

int main()
{
	int i,t;
	for(i=0;i<10;i++)
		head[i]=NULL;
	while(1)
	{
		printf("1.Insert\n2.Delete\n3.Search\n4.Display all Records\n5.Exit\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 :
			{
				insert();
			}
			break;

			case 2 :
			{
				delete();
			}
			break;

			case 3 :
			{
				search();
			}
			break;

			case 4 :
			{
				display();
			}
			break;

			case 5 :
			{
				return 0;
			}
			break;

			default : {}
		}
	}
}