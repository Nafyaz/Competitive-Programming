#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, k, i, j, cost, ans;
    ll T[9][9];
    vector<ll> path;

    cin >> n >> k;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cin >> T[i][j];

        if(i > 1)
            path.push_back(i);
    }

//    for(auto u : path)
//        cout << u << " ";

    ans = 0;
    while(1)
    {
        cost = T[1][path[0]];
        for(i = 1; i < path.size(); i++)
            cost += T[path[i-1]][path[i]];
        cost += T[path.back()][1];

        if(cost == k)
            ans++;

        if(next_permutation(path.begin(), path.end()) == 0)
            break;
    }

    cout << ans;
}

