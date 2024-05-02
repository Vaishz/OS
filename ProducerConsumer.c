#include <stdio.h>
#include <stdlib.h>

int full = 0, empty = 10, x = 0, mutex = 1;
void Producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("Producer produces the item %d", x);
    ++mutex;
}
void Consumer()
{
    --mutex;
    --full;
    ++empty;
    x--;
    printf("Consumer consumes the item %d", x);
    ++mutex;
}
int main()
{
    int n, i;
    printf("\n1. Press 1 for Producer \n2. Press 2 for Consumer \n3. Exit");
    
    for (i = 1; i > 0; i++)
    {
        printf("\nEnter the choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                Producer();
            else
            printf("Buffer is full");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                Consumer();
            else
                printf("Buffer is empty");
            break;
        case 3:
            printf("Exiting......");
            exit(0);
            break;
        default:
            printf("Invalid choice!!!!");
            break;
        }
    }
}
