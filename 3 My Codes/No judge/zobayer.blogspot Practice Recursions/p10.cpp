#include<bits/stdc++.h>
using namespace std;

int rec(int a, int b, int l)
{
    if(a == 0 || b == 0)
        return 0;
    if(l % a == 0 && l % b == 0)
        return l;
    return rec(a, b, l + 1);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", rec(a, b, max(a, b)));
}
