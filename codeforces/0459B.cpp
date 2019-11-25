#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    scanf("%d", &n);
    int a[n];

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a+n);

    int x = upper_bound(a, a+n, a[0]) - a;
    int y = n - (lower_bound(a, a+n, a[n-1]) - a);

    printf("%d %d", a[n-1] - a[0], x*y);
}
