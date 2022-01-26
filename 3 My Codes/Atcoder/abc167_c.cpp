#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j, x, ans, cost, skill[13], flag;
    int c[13], a[13][13];

    cin >> n >> m >> x;

    for(i = 0; i < n; i++)
    {
        cin >> c[i];
        for(j = 0; j < m; j++)
            cin >> a[i][j];
    }

    ans = INT_MAX;
    for(int mask = 1; mask < (1 << n); mask++)
    {
        cost = 0;
        memset(skill, 0, sizeof skill);

        for(i = 0; i < n; i++)
        {
            if(mask & (1<<i))
            {
                cost += c[i];

                for(j = 0; j < m; j++)
                    skill[j] += a[i][j];
            }
        }

        flag = 1;
        for(j = 0; j < m && flag; j++)
        {
            if(skill[j] < x)
                flag = 0;
        }

        if(flag)
            ans = min(ans, cost);
    }

    cout << (ans == INT_MAX? -1 : ans);
}
