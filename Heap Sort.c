
#include <stdio.h>

#define asize 100

struct heap
{
	int a[asize];
	int hsize ;
}H;

void swap(int *a,int *b)
{
	int temp=*b;
	*b=*a;
	*a=temp;
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void heapInsert(int key)
{
	H.hsize++;
	H.a[H.hsize]=key;
	int i=H.hsize;
	while(i>1 && H.a[i]>H.a[i/2])
	{
		swap(&H.a[i],&H.a[i/2]);
		i=i/2;
	}
	printf("%d is successfully inserted in Heap\n",key);
}

void displayHeap()
{
	int i;
	printf("Elements in the heap:-\n");
	for(i=1;i<=H.hsize;i++)
		printf("%d ",H.a[i]);
	printf("\n");
}

void delMax()
{
	if(H.hsize==0)
	{
		printf("Heap is empty,delMin can't be performed\n");
		return ;
	}

	int x=H.a[1];
	H.a[1]=H.a[H.hsize];
	H.hsize--;
	int i=1;
	while((2*i)<=H.hsize)
	{
		if((2*i)+1<=H.hsize && H.a[i]<max(H.a[2*i],H.a[(2*i)+1]))
		{
			if(H.a[(2*i)+1]>H.a[2*i])
			{
				swap(&H.a[i],&H.a[(2*i)+1]);
				i=(2*i)+1;
			}
			else
			{
				swap(&H.a[i],&H.a[(2*i)]);
				i=(2*i);	
			}

		}
		else if((2*i)+1>H.hsize && H.a[i]<H.a[2*i])
		{
			swap(&H.a[i],&H.a[(2*i)]);
			break;
		}
		else
			break;
	}
	printf("%d ",x);

}

int main()
{
	int t;
	H.hsize=0;
	while(1)
	{
		printf("1.Insert\n2.Display Heap\n3.Heap Sort\n4.Exit\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 :
			{
				int key;
				printf("Enter integer to be inserted\n");
				scanf("%d",&key);
				heapInsert(key);
			}
			break;

			case 2 :
			{
				displayHeap();	
			}
			break;

			case 3 :
			{
				int hsize=H.hsize;
				printf("Heap Sort:-\n");
				while(hsize--)
					delMax();
				printf("\n");	
			}
			break;

			case 4 :
			{
				return 0;
			}
		}
	}
}