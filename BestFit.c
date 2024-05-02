#include <stdio.h>

void main()
{
    int b[10], p[10], bno, pno, fragment[10], i, j, lowest = 10000, temp;
    static int barray[10] = {0}, parray[10];

    printf("Enter number of blocks: \n");
    scanf("%d", &bno);
    printf("Enter size of each block: \n");
    for (i = 0; i < bno; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("Enter number of processes: \n");
    scanf("%d", &pno);
    printf("Enter size of each process: \n");
    for (i = 0; i < pno; i++)
    {
        scanf("%d", &p[i]);
    }

    for (i = 0; i < pno; i++)
    {
        for (j = 0; j < bno; j++)
        {
            if (barray[j] != 1)           //s if the block at index j has not been already assigned to a process.
            {
                temp = b[j] - p[i];
                if (temp > 0 && lowest > temp)
                    {
                        parray[i] = j;
                        lowest = temp;
                    }
            }
        }

        fragment[i] = lowest;
        barray[parray[i]] = 1;
        lowest = 10000;
    }
    printf("Process no\tProcess size\tBlock no\tBlock size\tFragment\n");
    for (i = 0; i < pno && parray[i] != 0; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, p[i], parray[i], b[parray[i]], fragment[i]);
    }
}
