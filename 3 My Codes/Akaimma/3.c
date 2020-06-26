//3.C program to find all factors of a number
#include <stdio.h>
int main()
{
    int i,n;
    printf("Input number: ");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        if(n%i==0)
            printf("%d,",i);
    }
    printf("%d",n);
}
