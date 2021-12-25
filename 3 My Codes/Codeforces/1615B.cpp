#include<bits/stdc++.h>
using namespace std;

int prefixBits[200005][20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int i, j, n;

    for(i = 1; i < 200005; i++)
    {
        n = i;

        for(j = 0; n; j++, n/=2)
        {
            prefixBits[i][j] = prefixBits[i-1][j];

            if(n&1)
                prefixBits[i][j]++;
        }
    }

    int t, l, r, mx, x;

    cin >> t;
    while(t--)
    {
        cin >> l >> r;

        mx = 0;
        for(i = 0; i < 20; i++)
        {
            x = prefixBits[r][i] - prefixBits[l-1][i];
            mx = max(x, mx);
        }

        cout << r - l + 1 - mx << "\n";
    }
}
