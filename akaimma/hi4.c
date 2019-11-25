#include<stdio.h>
int main()
{
    int a, b = 0, temp;
    scanf("%d", &a);
    temp = a;

    while(temp != 0)
    {
        b = 10*b + temp%10;
        temp = temp/10;
    }

    if(a == b)
        printf("YES");
    else
        printf("NO");
}
