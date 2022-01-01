#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, i, n, l, r;
    vector<int> leftToRight[1003], rightToLeft[1003];

    cin >> t;

    while(t--)
    {
        mp.clear();
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> l >> r;

            leftToRight[l].push_back(r);
            rightToLeft[r].push_back(l);
        }

        for(i = 1; i <= n; i++)
        {
            if()
        }
    }
}
