#include<bits/stdc++.h>
using namespace std;

string s, t, dp[109][109];
int lcs[109][109], vis[109][109];


int call(int i, int j)
{
    if(i == s.size() || j == t.size())
        return 0;

    if(lcs[i][j])
        return lcs[i][j];
    if(s[i] == t[j])
        return lcs[i][j] = 1 + call(i+1, j+1);

    lcs[i][j] = max(call(i+1, j), call(i, j+1));

    return lcs[i][j];
}

string call2(int i, int j)
{
    if(i == s.size() || j == t.size())
        return "";

    if(vis[i][j] == 1)
        return dp[i][j];

    vis[i][j] = 1;

    if(s[i] == t[j])
        return dp[i][j] = s[i] + call2(i+1, j+1);

    if(lcs[i+1][j] > lcs[i][j+1])
        return dp[i][j] = call2(i+1, j);
    else if(lcs[i][j+1] > lcs[i+1][j])
        return dp[i][j] = call2(i, j+1);
    else
        return dp[i][j] = min(call2(i+1, j), call2(i, j+1));
}

int main()
{
    int T, caseno = 0, ans;
    cin >> T;
    while(T--)
    {
        memset(lcs, 0, sizeof(lcs));
        cin >> s >> t;

        cout << "Case " << ++caseno << ": ";
        ans = call(0, 0);
        if(!ans)
            cout << ":(";
        else
        {
            memset(vis, 0, sizeof(vis));
            cout << call2(0, 0);
        }
        cout << endl;
    }
}
