#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define N 10009

vector<vector<int>> v(N);
int a[N];

vector<int> func(int n)
{
    if(v[n].size() != 0)
        return v[n];
    if(!n)
    {
        v[n].push_back(0);
        return v[n];
    }

    vector<int> left = func(n-1), ret;
    map<int, int> mp;

    for(int i = 0; i < left.size(); i++)
    {
        mp[ left[i] ]++;
        mp[ left[i]+1 ] ++;
    }

    for(auto u : mp)
    {
        if(u.ss == 1)
            ret.push_back(u.ff);
    }

    return v[n] = ret;
}

int main()
{
    int t, caseno = 0, n, q, i, ans;
    int b, e;

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        cout << "Case " << ++caseno << ":\n";
        cin >> q;
        while(q--)
        {
            cin >> b >> e;

            ans = 0;
            vector<int> temp = func(e-b);
            for(i = 0; i < temp.size(); i++)
                ans = ans ^ a[temp[i] + b];

            cout << ans << "\n";
        }
    }
}

