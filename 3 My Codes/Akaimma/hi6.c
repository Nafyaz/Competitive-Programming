#include<stdio.h>
int add(int a, int b)
{
    return a+b;
}
int sub(int a, int b)
{
    return a-b;
}
int main()
{
    int x = 5, y = 9;
    int p = add(x, y);
    int q = sub(x, y);
    printf("%d %d", p, q);
}
