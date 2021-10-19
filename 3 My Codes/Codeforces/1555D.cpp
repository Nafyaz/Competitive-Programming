#include<bits/stdc++.h>
using namespace std;

int pref[6][200005];

int main()
{
    int n, m, i, j, l, r, cost;
    string s, unit = "abc";

    cin >> n >> m >> s;

    for(i = 0; i < 6; i++)
    {
        pref[i][0] = 0;
        for(j = 0; j < n; j++)
            pref[i][j+1] = pref[i][j] + (unit[j%3] != s[j]);

        next_permutation(unit.begin(), unit.end());
    }

    while(m--)
    {
        cin >> l >> r;

        cost = INT_MAX;
        for(i = 0; i < 6; i++)
            cost = min(cost, pref[i][r] - pref[i][l-1]);

        cout << cost << "\n";
    }
}
