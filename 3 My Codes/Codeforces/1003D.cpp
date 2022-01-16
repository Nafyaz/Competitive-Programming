#include<bits/stdc++.h>
using namespace std;

int dCnt[32];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, i, a, b, val, ans;

    cin >> n >> q;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        dCnt[(int)log2(a)]++;
    }

    while(q--)
    {
        cin >> b;

        for(i = 32, ans = 0; i >= 0; i--)
        {
            a = (1 << i);

            if(!dCnt[i] || a > b)
                continue;

            val = min(b/a, dCnt[i]);

            b -= val*a;
            ans += val;
        }

        if(b)
            cout << "-1\n";
        else
            cout << ans << "\n";
    }
}
