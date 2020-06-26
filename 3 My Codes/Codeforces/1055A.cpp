#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, s, i, flag = 0;
    scanf("%d %d", &n, &s);

    int a1[n+1], a2[n+1];

    for(i = 1; i <= n; i++)
        scanf("%d", &a1[i]);
    for(i = 1; i <= n; i++)
        scanf("%d", &a2[i]);

    if(a1[1] == 0)
    {
        printf("NO");
        return 0;
    }
    if(a1[s] == 1)
    {
        printf("YES");
        return 0;
    }
    if(a2[s] == 0)
    {
        printf("NO");
        return 0;
    }
    for(i = s+1; i <= n; i++)
    {
        if(a1[i] == 1 && a2[i] == 1)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}
