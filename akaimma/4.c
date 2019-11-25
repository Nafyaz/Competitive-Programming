//4.C program to check whether a number is Strong number or not
#include<stdio.h>
int factorial(int a)
{
    int i,result=1;
    for(i=1;i<=a;i++)
        result=result*i;

    return result;
}
int main()
{
    int n,x,sum=0;
    printf("Input number: ");
    scanf("%d",&n);

    x=n;

    while(x!=0)
    {
        sum=sum+factorial(x%10);
        x=x/10;
    }
    if(sum==n)
        printf("%d is STRONG NUMBER",n);
    else
        printf("%d is NOT STRONG NUMBER",n);

}
