#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

set<pair<int, int>> a;
int ans[200005];

int main()
{
    int n, m, d, i, x;

    cin >> n >> m >> d;

    for(i = 1; i <= n; i++)
    {
        cin >> x;
        a.insert({x, i});
    }

//    for(auto u : a)
//        cout << u.ff << " " << u.ss << "\n";

    for(i = 1; !a.empty(); i++)
    {
        queue<pair<int, int>> q;

        auto it = a.begin();

        while(it != a.end())
        {
            q.push(*it);
            ans[(*it).ss] = i;

            it = a.upper_bound({(*it).ff + d, INT_MAX});
        }

        while(!q.empty())
        {
//            cout << q.front().ff << " ";
            a.erase(q.front());
            q.pop();
        }
//        cout << "\n";
    }

    cout << i-1 << "\n";
    for(i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
