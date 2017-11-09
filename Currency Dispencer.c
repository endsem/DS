
#include <stdio.h>
int main()
{
	printf("Enter No. of Denominations\n");
	int n;
	scanf("%d",&n);
	int d[n],i,f[n];
	for(i=0;i<n;i++)
		f[i]=0;
	printf("Enter Values of denominations in descending order\n");	
	for(i=0;i<n;i++)
		scanf("%d",&d[i]);
	printf("Enter Bill to be paid\n");
	int b,x;
	scanf("%d",&b);
	x=b;
	i=0;
	while(x>0 && i<n)
	{
		f[i]=x/d[i];
		x=x-(f[i]*d[i]);
		i++;
	}
	if(x==0)
	{
		for(i=0;i<n;i++)
		printf("%d * %d\n",d[i],f[i]);
	}
	else
	printf("Bill cannot be paid\n");
	



}
