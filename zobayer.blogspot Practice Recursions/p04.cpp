#include<bits/stdc++.h>
using namespace std;

void rec(int n)
{
    if(n < 1)
        return;
    if(n == 1)
    {
        printf("+ x ");
        return;
    }
    rec(n - 1);
    printf("+ x^%d ", n);
}

int main()
{
    int n;
    scanf("%d", &n);
    n--;
    if(n >= 0)
        printf("1 ");
    rec(n);
}
