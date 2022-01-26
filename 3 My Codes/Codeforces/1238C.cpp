#include<bits/stdc++.h>
using namespace std;

int p[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, h, n, i, ans;

    cin >> q;

    while(q--)
    {
        cin >> h >> n;

        for(i = 0; i < n; i++)
            cin >> p[i];

        p[n] = 0;

        ans = 0;
        for(i = 1; i < n; i++)
        {
            if(p[i] == p[i+1]+1)
                i++;
            else
                ans++;
        }

        cout << ans << "\n";
    }
}
