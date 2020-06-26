#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, x;
    scanf("%d", &n);
    int a[n];


    for(i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        a[x - 1] = i;
    }

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
}
