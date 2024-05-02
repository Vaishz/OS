#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void forkeg()
{
    pid_t p;
    p=fork();

    if (p<0)
    {
        printf("Undefined");
        exit(1);
    }
    else if (p==0)
    {
        printf("Hi Child i am");
    }
    else{
            printf("hi parent i mam");
    }
}

int main()
{
    forkeg();
    return 0;
}