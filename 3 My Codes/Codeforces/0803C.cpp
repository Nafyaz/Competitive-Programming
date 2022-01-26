#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, i, sum, gcd;
    vector<ll> divisors;

    cin >> n >> k;

    if(k > 1000006)
    {
        cout << -1;
        return 0;
    }

    for(i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            divisors.push_back(i);
            if(i != n/i)
                divisors.push_back(n/i);
        }
    }

    sort(divisors.begin(), divisors.end(), greater<ll>());

    gcd = -1;
    for(auto d : divisors)
    {
        sum = n/d;

        if(k*(k+1)/2 <= sum)
        {
            gcd = d;
            break;
        }
    }

    if(gcd == -1)
        cout << -1;
    else
    {
        for(i = 1; i < k; i++)
            cout << i*gcd << " ";
        cout << n - (k-1)*k/2*gcd;
    }
}
