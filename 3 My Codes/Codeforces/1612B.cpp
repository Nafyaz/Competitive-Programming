#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a, b, i, val;
    int ans[102];

    cin >> t;

    while(t--)
    {
        cin >> n >> a >> b;

        ans[1] = a;
        ans[n] = b;

        for(val = n, i = 2; val >= 1; val--)
        {
            if(val == a || val == b)
                continue;
            ans[i] = val;
            i++;
        }

        if(*min_element(ans+1, ans+n/2+1) == a && *max_element(ans+n/2+1, ans+n+1) == b)
        {
            for(i = 1; i <= n; i++)
                cout << ans[i] << " ";
            cout << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
}
