#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, i, a, cnt, isConsecutive;

    cin >> t;

    while(t--)
    {
        cin >> n;

        set<ll> s;
        cnt = isConsecutive = 0;

        for(i = 0; i < n; i++)
        {
            cin >> a;

            if(a == 1)
                cnt++;

            if(s.find(a+1) != s.end() || s.find(a-1) != s.end())
                isConsecutive = 1;
            s.insert(a);
        }

        if(cnt == 0 || cnt == n)
            cout << "YES\n";
        else if(isConsecutive)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
