#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int m;
int rec(int *a, int n)
{
    if(n == -1)
        return m;
    n--;
    if(m < a[n])
        m = a[n];
    return rec(a, n);
}
int main()
{
    int n, i;
    scanf("%d", &n);
    int a[n];

    FORAB(i, 0, n)
        scanf("%d", &a[i]);

    printf("%d", rec(a, n));
}
