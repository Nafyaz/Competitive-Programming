#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, k, i, a, flag;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        set<ll> s;

        flag = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;

            if(s.find(a+k) != s.end() || s.find(a-k) != s.end())
                flag = 1;

            s.insert(a);
        }

        cout << (flag? "Yes\n" : "No\n");
    }
}
