//Follow jiangly

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, m, i, j, x, y, flag, ans;
    ll a[200005], mx[200005];

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            mx[i+1] = 0;
        }

        cin >> m;
        for(i = 0; i < m; i++)
        {
            cin >> x >> y;
            mx[y] = max(x, mx[y]);
        }

        for(i = n-1; i > 0; i--)
            mx[i] = max(mx[i], mx[i+1]);

        flag = 1;
        ans = 0;
        for(i = 0; i < n;)
        {
            ans++;
            x = 0;
            for(j = i; j < n; j++)
            {
                x = max(x, a[j]);
                if(mx[j-i+1] < x)
                    break;
            }

            if(j == i)
            {
                flag = 0;
                break;
            }

            i = j;
        }

        cout << (flag? ans : -1) << "\n";
    }
}
