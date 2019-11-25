#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n;
    scanf("%d", &n);
    int a[2*n];
    for(i = 0; i < 2*n; i++)
        scanf("%d", &a[i]);

    sort(a, a+2*n);
    if(a[0] == a[2*n-1])
    {
        printf("-1");
        return 0;
    }
    for(i = 0; i < 2*n; i++)
        printf("%d ", a[i]);
}
