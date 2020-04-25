#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, q, i, j, pos[50009], x, mx;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> q;
        vector<pair<int, int>> v;

        mx = -1;
        for(i = 1; i <= k; i++)
        {
            cin >> pos[i];
            mx = max(mx, pos[i]);
            v.push_back({pos[i], i});
        }

        sort(v.begin(), v.end());

        while(q--)
        {
            cin >> x;

        }
    }
}
