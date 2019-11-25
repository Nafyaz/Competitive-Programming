#include<bits/stdc++.h>
using namespace std;

void rec(int n)
{
    if(n == 0)
        return;
    int a;
    scanf("%d", &a);
    if((a & 1) == 0)
        printf("%d ", a);
    rec(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    rec(n);
}
