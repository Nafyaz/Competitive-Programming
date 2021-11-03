#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, i, j, ans;
    string b[2];

    cin >> T;

    while(T--)
    {
        cin >> n >> b[0] >> b[1];

        ans = 0;

        for(i = 0; i < n; i++)
        {
            if(b[0][i] != b[1][i])
                ans += 2;
            else if(b[0][i] == '0' && b[1][i] == '0')
                ans += 1;
        }

        for(i = 0; i+1 < n; i++)
        {
            if(b[0][i] == b[1][i] && b[0][i+1] == b[1][i+1] && b[0][i] != b[0][i+1])
            {
                ans++;
                i++;
            }
        }

        cout << ans << "\n";
    }
}
