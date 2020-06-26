#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, x = 0, y = 0;
    scanf("%d", &n);
    int a[n/2];
    for(i = 0; i < n/2; i++)
        scanf("%d", &a[i]);
    sort(a, a+n/2);
    for(i = 0; i < n/2; i++)
    {
        x += abs(a[i] - 2*(i + 1));
        y += abs(a[i] - (2*i + 1));
    }
    printf("%d", min(x, y));
}
