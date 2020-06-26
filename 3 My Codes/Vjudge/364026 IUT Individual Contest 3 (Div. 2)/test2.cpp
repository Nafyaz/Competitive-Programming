#include<stdio.h>
#include <math.h>
int main()
{
    int i,j,k,N,d=4;
    scanf("%d",&N);
    if(N==1)
    {
        printf("1");
    }
    if(N==2)
    {
        printf("2");
    }
    if(N==3)
    {
        printf("3");
    }
    for(i=2;i<=14;i++)
    {
        if(pow(2,i)<=N && N<=pow(2,(i+1)))
        {
            printf("%d",d);
            break;
        }
        else{d=d+1;}
    }
    return 0;
}
