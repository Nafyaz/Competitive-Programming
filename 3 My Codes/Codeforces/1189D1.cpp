#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, u, v, node;
    scanf("%d", &n);
    vector <int> a[n+1];

    for(i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(i = 1; i <= n; i++)
    {
        if(a[i].size() == 2)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}
