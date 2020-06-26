#include<bits/stdc++.h>
using namespace std;

int n, total, y[55];
bool dp[55][50009], vis[55][50009];
map<pair<int, int>, set<int> > mp;

bool call(int i, int j)
{
    if(vis[i][j])
        return dp[i][j];

    vis[i][j] = 1;

    int p, q;
    if(i == 0 && j == y[i] || j == 0)
        return dp[i][j] = 1;
    else if(i == 0)
        return dp[i][j] = 0;

    p = call(i-1, j);
    if(p)
    {
        for(auto u : mp[{i-1, j}])
            mp[{i, j}].insert(u);
    }

    if(j >= y[i])
    {
        q = call(i-1, j-y[i]);
        if(q)
        {
            for(auto u : mp[{i-1, j-y[i]}])
                mp[{i, j}].insert(u);
            mp[{i, j}].insert(y[i]);
        }
        return dp[i][j] = p|q;
    }


    return dp[i][j] = p;
}

int main()
{
    int t, i, j, fgx, x, mx;
    cin >> t;

    while(t--)
    {
        cin >> n;
        memset(vis, 0, sizeof vis);
        mp.clear();
        total = 0;
        for(i = 0; i < n; i++)
        {
            cin >> y[i];
            total += y[i];
        }

        fgx = 0, x = 0, mx = 0;
        for(i = 0; i <= total; i++)
        {
            if(call(n-1, i))
            {
//                cout << i << " " << fgx << endl;
//                for(auto u : mp[{n-1, i}])
//                    cout << u << " ";
//                cout << endl << endl << endl;
                if(fgx < mp[{n-1, i}].size())
                {
                    x = i;
                    fgx = mp[{n-1, i}].size();
                }
            }
        }

//        for(i = 0; i < n; i++)
//        {
//            for(j = 0; j <= total; j++)
//            {
//                cout <<
//            }
//        }
        cout << fgx << " " << x << endl;
    }
}
