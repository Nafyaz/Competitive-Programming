#include<bits/stdc++.h>
using namespace std;

string a, b;

int dp[65][65];

int lcs(int i, int j)
{
    if(i == (int)a.size() || j == (int)b.size())
        return dp[i][j] = 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(a[i] == b[j])
        return dp[i][j] = 1 + lcs(i+1, j+1);
    else
        return dp[i][j] = max(lcs(i+1, j), lcs(i, j+1));
}

int main()
{
    int t, i, j;
    string s;

    cin >> t;
    while(t--)
    {
        cin >> a >> b;

        memset(dp, -1, sizeof dp);

        cout << lcs(0, 0) << "\n";

        i = j = 0;
        s = "";

        while(dp[i][j] != 0)
        {
//            cout << a[i] << " ";
            if(dp[i+1][j] == dp[i][j])
                i++;
            else if(dp[i][j+1] == dp[i][j])
                j++;
            else
            {
                s = s + a[i];
                i++;
                j++;
            }

//            cout << "\n";
        }

        cout << s << "\n";
    }
}
