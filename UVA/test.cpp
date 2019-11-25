#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<conio.h>

int checkprime(int n)
{
    int s;

    for(s=2;s<n;s++)
    {
        if(n%s==0)
            break;
    }
    if(n%s==0)
        return 1;
}
int main()
{
    int a,i,j,s;
    int b[1000];
    scanf("%d",&a);

    for(i=0;i<a;i++)
    {
        for(j=0;j<=i;j++)
        {
            if (a==i+j&& checkprime(i)==1 && checkprime(j)==1)
                break;
        }
        if(a==i+j&& checkprime(i)==1 && checkprime(j)==1)
            break;
    }
    printf("%d %d",i,j);
}
