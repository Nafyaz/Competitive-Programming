#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll z = -1, two = -1;
deque <ll> d;

void to_trinary(ll n)
{

    d.push_front(n%3);
    if (!n)
        return;
    to_trinary(n/3);
}

int main()
{
    ll q, n, i;
    cin >> q;
    while(q--)
    {
        d.clear();

        cin >> n;
        to_trinary(n);
        i = 0;
        z = two = -1;

        for(auto u : d)
        {
            if(u == 0)
                z = i;
            if(u == 2)
            {
                two = i;
                break;
            }
            i++;
        }

        if(two == -1)
        {
            cout << n << endl;
            continue;
        }

        i = 0;
        ll ans = 0;
        for(auto u : d)
        {
            if(i < z)
                ans = (ans*3) + u;
            else if(i == z)
                ans = (ans*3 + 1);
            else if(i > z)
                ans = 3*ans;
            i++;
        }

        cout << ans << endl;
    }
}

