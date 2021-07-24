#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)


void rec(int n)
{
    if(n == 0)
        return;

    int a;
    scanf("%d", &a);
    rec(n - 1);
    printf("%d ", a);
}

int main()
{
    int n;
    scanf("%d", &n);
    rec(n);
}

