#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, t, i;
    scanf("%d %d", &n, &t);
    int a[n+1];
    for(i = 1; i < n; i++)
        scanf("%d", &a[i]);

    i = 1;
    while(i + a[i] <= t)
    {
        if(i + a[i] == t)
        {
            printf("YES");
            return 0;
        }
        i = i + a[i];
    }
    printf("NO");
}
