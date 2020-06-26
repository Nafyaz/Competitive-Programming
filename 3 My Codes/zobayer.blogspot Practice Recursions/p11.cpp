#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int rec(int *a, int n, int i)
{
    if(i == n - 1)
        return a[i];

    return max(a[i], rec(a, n, i + 1));
}
int main()
{
    int n, i;
    scanf("%d", &n);
    int a[n];

    FORAB(i, 0, n)
        scanf("%d", &a[i]);

    printf("%d", rec(a, n, 0));
}

