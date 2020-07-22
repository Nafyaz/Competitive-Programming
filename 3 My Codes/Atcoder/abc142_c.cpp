#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int n, i;

    cin >> n;

    vector<pair<int, int>>v(n);

    for(i = 0; i < n; i++)
    {
        cin >> v[i].ff;
        v[i].ss = i+1;
    }

    sort(v.begin(), v.end());

    for(i = 0; i < n; i++)
        cout << v[i].ss << " ";
}
