#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, ans = 0, c;
    scanf("%d", &n);
    getchar();
    char a[n][n+1];
    for(i = 0; i < n; i++)
        gets(a[i]);

    for(i = 0; i < n; i++)
    {
        c = 0;
        for(j = 0; j < n; j++)
        {
            if(a[i][j] == 'C')
                c++;
        }
        ans += c*(c-1)/2;
    }
    for(i = 0; i < n; i++)
    {
        c = 0;
        for(j = 0; j < n; j++)
        {
            if(a[j][i] == 'C')
                c++;
        }
        ans += c*(c-1)/2;
    }
    printf("%d", ans);
}
