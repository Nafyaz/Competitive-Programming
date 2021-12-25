#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

void getTLE()
{
    while(1);
}

bool cmp(pair<ll, ll> x, pair<ll, ll> y)
{
    if(x.ss != y.ss)
        return x.ss < y.ss;
    return x.ff <= y.ff;
}


int main()
{
    freopen("in.txt", "r", stdin);
    ll n, d, i, ans, last;

    cin >> n >> d;
    vector <pair <ll,ll>> p(n);
    for(auto &e : p)
        cin >> e.first >> e.ss;
    cout << p.size() << endl;
    sort(p.begin(), p.end(),cmp);
    cout << p.size() << endl;

//    getTLE();

    ans = last = 0;
    for(i = 0; i < n; i++)
    {
        if(p[i].ff > last)
        {
            cout << "ans: "<< i<< ' ' << p[i].ff << ", " << p[i].ss << "\n";
            ans ++;
            last = p[i].ss + d -1;
        }

        if(p[i].ff != 1 || p[i].ff != 1)
        {
            cout << "ans: "<< i<< ' ' << p[i].ff << ", " << p[i].ss << "\n";
        }
    }

    cout << ans;
}
