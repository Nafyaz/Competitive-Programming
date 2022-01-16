#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int p[100005];
pair<int, int> t[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> p[i];

    for(i = 0; i < m; i++)
    {
        cin >> t[i].ff;
        t[i].ss = i;
    }

    sort(t, t+m);


}
