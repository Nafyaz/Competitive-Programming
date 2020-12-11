#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll T, n, i, j, mx, fib[60], val[209];
    char c;
    map<ll, ll> mp;
    string s, ans;

    fib[0] = fib[1] = 1;
    mp[1] = 1;
    for(i = 2; i < 60; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        mp[fib[i]] = i;
    }

    cin >> T;
    while(T--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> val[i];

        scanf("%c", &c);
        getline(cin, s);

        j = 0;
        ans = string(200, ' ');
//        cout << s << "\n";
//        cout << "*" << ans << "*\n";
        mx = 0;
        for(i = 0; i < (ll)s.size() && j < n; i++)
        {
//            cout << i << "\n";
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
//                cout << val[j] << " " << mp[val[j]] << " " << s[i] << "\n";
                ans[mp[val[j]] - 1] = s[i];
                mx = max(mx, mp[val[j]]);
                j++;
            }
        }

        cout << ans.substr(0, mx) << "\n";
    }
}
/*
1
4
1 3 2 5
A a B b C c D d E e
*/
