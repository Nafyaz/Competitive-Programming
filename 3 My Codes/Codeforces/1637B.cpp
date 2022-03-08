#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, i, j, ans;
    int b[102], zeros[102];

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            cin >> b[i];

            zeros[i] = zeros[i-1];

            if(b[i] == 0)
                zeros[i]++;
        }

        ans = 0;
        for(i = 1; i <= n; i++)
        {
            for(j = i; j <= n; j++)
                ans += zeros[j] - zeros[i-1] + j-i+1;
        }

        cout << ans << "\n";
    }
}
