#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int n, i, x;
    cin >> n;
    vector <pair <int, int> > v;
    for(i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back({x, i+1});
    }

    sort(v.begin(), v.end() , greater<pair<int, int> >());

    cout << v[0].ss << " " << v[1].ff;
}
