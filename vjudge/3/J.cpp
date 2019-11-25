#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n, greater<int>());
    for(i = 0; i < k && i < n; i++)
    {
        a[i] = m;
    }
    sort(a, a+n, greater<int>());

    if(a[0] == m)
        printf("YES\n");
    else
        printf("NO\n");
}
