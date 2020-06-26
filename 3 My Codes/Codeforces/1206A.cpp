#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, m;
    scanf("%d", &n);
    int a[n];

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &m);
    int b[m];

    for(i = 0; i < m; i++)
        scanf("%d", &b[i]);

    sort(a, a+n);
    sort(b, b+m);

    printf("%d %d", a[n-1], b[m-1]);
}
