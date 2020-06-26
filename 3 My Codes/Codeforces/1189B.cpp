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

    if(a[n-3] + a[n-2] <= a[n-1])
    {
        printf("NO");
        return 0;
    }

    printf("YES\n");
    swap(a[n-1], a[n-2]);
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
}
