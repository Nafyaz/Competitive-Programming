#include<bits/stdc++.h>
using namespace std;

void rec(int n)
{
    if(!n)
        return;
    printf("%d", n%10);
    rec(n/10);
}
int main()
{
    int n;
    scanf("%d", &n);
    rec(n);
}
