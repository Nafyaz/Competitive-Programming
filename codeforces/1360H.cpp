#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, a[109];

string toS(ll v)
{
    string ret;
    while(v)
    {
        if(v&1)
            ret = ret + '1';
        else
            ret = ret + '0';
        v >>= 1;
    }
    while(ret.size() < m)
        ret = ret + '0';
    reverse(ret.begin(), ret.end());
    return ret;
}

ll toLL(string s)
{
    ll ret = 0;
    for(ll i = 0; i < s.size(); i++)
        ret = (ret << 1) + (s[i] == '1');
    return ret;
}

bool check(ll v)
{
    ll left = lower_bound(a, a+n, v) - a;
    if(a[left] == v)
        return 0;

    ll right = n-left;
//    cout << left << " " << right;
    if(n&1)
        return v-left == (1LL<<m)-1 -v - right;
    else
        return v-left+1 == (1LL<<m)-1 -v - right;
}

int main()
{
    ll t, i, flag;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i = 0; i < n; i++)
        {
            cin >> s;
            a[i] = toLL(s);
        }

        sort(a, a+n);
        ll med = (1LL << (m-1));

        flag = 0;
        for(i = med; i >= 0 && i >= med - 100; i--)
        {
            if(check(i))
            {
                flag = 1;
                break;
            }
        }

        if(flag)
        {
            cout << toS(i) << endl;
            continue;
        }

        for(i = med; i < (1LL<<m) && i <= med + 100; i++)
        {
            if(check(i))
            {
                flag = 1;
                break;
            }
        }

        cout << toS(i) << endl;
    }
}
