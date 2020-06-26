#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, m;
    scanf("%d %d", &n, &m);
    int a[m];
    for(i = 0; i < m; i++)
        scanf("%d", &a[i]);
    sort(a, a+m);
    if(a[0] == 1 || a[m-1] == n)
    {
        printf("NO");
        return 0;
    }
    for(i = 1; i < m-1; i++)
    {
        if(a[i-1] + 1 == a[i] && a[i] == a[i+1] - 1)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}
