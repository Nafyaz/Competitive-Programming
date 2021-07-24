#include<bits/stdc++.h>
using namespace std;

int rec(int n)
{
    if(n == 0)
        return 1;
    return n * rec(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", rec(n));
}

