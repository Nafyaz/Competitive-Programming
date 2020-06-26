#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, k;
    scanf("%d %d", &n, &k);

    int a[n];

    for(i = 0; i <n; i++)
        scanf("%d", &a[i]);

    sort(a, a+n);

    if(k > n)
        printf("-1");
    else
        printf("%d %d\n", a[n - k], a[n - k]);
}
