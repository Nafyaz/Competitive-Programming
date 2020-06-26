#include<bits/stdc++.h>
using namespace std;

int rec(int a, int b)
{
    if(b == 0)
        return a;
    return rec(b, a%b);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", rec(a, b));
}

