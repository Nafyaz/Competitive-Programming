#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int n, m, i;
    cin >> n;
    int a, b, c;
    map<int, int> num;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        num[a]++;
    }

    cin >> m;

    vector<pair<pair<int, int>, int>> sat(m);

    for(i = 0; i < m; i++)
    {
        cin >> b;
        sat[i].ff.ff = num[b];
        sat[i].ss = i;
    }
    for(i = 0; i < m; i++)
    {
        cin >> c;
        sat[i].ff.ss = num[c];
    }

    sort(sat.begin(), sat.end(), greater<pair<pair<int, int>, int>>());

    cout<< sat[0].ss + 1;

}
