#include<stdio.h>
int is_prime(int n)
{
    int i, flag = 0;
    for(i = 2; i <= n/2; i++)
    {
        if(n%i == 0)
            flag = 1;
    }
    if(flag == 1)
        printf("Not prime");
    else
        printf("Prime");
}
int main()
{
    int n;
    scanf("%d", &n);
    is_prime(n);
}
