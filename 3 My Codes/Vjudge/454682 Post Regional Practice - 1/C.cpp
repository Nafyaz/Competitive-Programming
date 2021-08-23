#include<bits/stdc++.h>
using namespace std;

bool Is_same(int h, int m)
{
    int d = h%10;

    if(h/10 > 0 && d != h/10)
        return 0;

    if(d != m%10)
        return 0;

    if(m/10 > 0 && d != m/10)
        return 0;

    return 1;
}

int main()
{
    int t, h, m, i, j, ans;

    cin >> t;

    while(t--)
    {
        cin >> h >> m;

        ans = 0;
        for(i = 0; i < h; i++)
        {
            for(j = 0; j < m; j++)
            {
                ans += Is_same(i, j);
            }
        }

        cout << ans << "\n";
    }
}
