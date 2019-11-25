#include<stdio.h>

void lol(int a)
{
    if(a == 0)
        return;
    printf("%d", a);
}

int main()
{
    lol(11);
    lol(0);
    lol(-12);
}
