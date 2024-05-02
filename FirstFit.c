#include<stdio.h>

void main()
{
	int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i;
	for(i=0; i<10; i++)
	{
		flags[i]=0;
		allocation[i]=-1;
	}
	printf("Enter number of blocks: \n");
	scanf("%d", &bno);
	printf("Enter size of each block: \n");
	for (i=0; i<bno; i++)
	{
		scanf("%d", &bsize[i]);
	}
	printf("Enter number of processes: \n");
	scanf("%d", &pno);
	printf("Enter size of each process: \n");
	for (i=0; i<pno; i++)
	{
		scanf("%d", &psize[i]);
	}

	for (i=0; i<pno; i++)
	{
		for (int j=0; j<bno; j++)
		{
			if (bsize[j]>=psize[i] && flags[j]==0)
			{
				allocation[i]=j;
				flags[j]=1;
				break;
			}
		}
	}
	printf("\n Process No \t Process Size \t Block No\n");
	for(i=0; i<pno; i++)
	{
		printf("%d\t\t%d\t\t", i+1, psize[i]);
		if (allocation[i] != -1)
			printf("%d\n", allocation[i] + 1);
		else
			printf("Not allocated\n");
	}
}
