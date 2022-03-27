#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, flag;

    set<pair<pair<ll, ll>, ll>> s;
    for(a = 1; a <= 1000; a++)
    {
        for(b = a+1; b <= 1000; b++)
        {
            c = sqrt(a*a + b*b);
            if(c*c == a*a + b*b && c <= 1000)
            {
                flag = 1;
                for(auto u : s)
                {
                    if(c%u.ss == 0)
                        flag = 0;
                }

                if(flag)
                    s.insert({{a, b}, c});
            }
        }
    }

    cin >> a >> b;

    if(a > b)
        swap(a, b);

    for(auto u : s)
    {
        if(a%u.ss == 0 && b%u.ss == 0)
        {
            cout << "YES\n";

            cout << "0 0\n";
            cout << -a/u.ss*u.ff.ss << " " << a/u.ss*u.ff.ff << "\n";
            cout << b/u.ss*u.ff.ff << " " << b/u.ss*u.ff.ss << "\n";

            return  0;
        }
    }

    cout << "NO";
}
