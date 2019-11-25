#include<bits/stdc++.h>
using namespace std;

int rec(int n)
{
    if(n == 1 || n == 2)
        return 1;
    return rec(n - 1) + rec(n - 2);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", rec(n));
}
