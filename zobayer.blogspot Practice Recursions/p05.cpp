#include<bits/stdc++.h>
using namespace std;

int rec(int x, int n)
{
    if(n == 1)
        return 1;
    return pow(x, n - 1) + rec(x, n - 1);
}

int main()
{
    int x, n;
    scanf("%d %d", &x, &n);

    printf("%d", rec(x, n));
}
