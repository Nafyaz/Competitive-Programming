#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000009

bool flag[N];
vector<ll> primes;
map<ll, ll> phi;

void linsieve()
{
    ll i, j;
    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes.push_back(i);
        for(j = 0; j < primes.size() && i * primes[j] < N; j++)
        {
            flag[i * primes[j]] = 1;
            if(i % primes[j] == 0)
                break;
        }
    }
}

ll PHI(ll n)
{
    if(phi[n] != 0)
        return phi[n];

    ll i, cnt, ret = n, temp = n;
    for(i = 0; primes[i] * primes[i] <= n; i++)
    {
        for(cnt = 0; n%primes[i] == 0; cnt++)
            n /= primes[i];
        if(cnt)
            ret = ret / primes[i] * (primes[i] - 1);
    }

    if(n > 1)
        ret = ret / n * (n - 1);

    return phi[temp] = ret;
}

int main()
{
    linsieve();

    ll t, caseno = 0, n, q, x, i, j;

    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        vector<ll> div;
        for(i = 1; i * i < n; i++)
        {
            if(n%i == 0)
            {
                div.push_back(i);
                div.push_back(n/i);
            }
        }
        if(i * i == n)
            div.push_back(i);

        sort(div.begin(), div.end());

        ll presum[div.size()];
        for(i = 0; i < div.size(); i++)
        {
            if(!i)
                presum[i] = PHI(n/div[i]);
            else
                presum[i] = presum[i-1] + PHI(n/div[i]);

//            cout << div[i] << " " << presum[i] << endl;
        }

        cout << "Case " << ++caseno << endl;
        while(q--)
        {
            cin >> x;
            ll pos = lower_bound(div.begin(), div.end(), x+1) - div.begin();
            if(!pos)
                cout << 0 << endl;
            else
                cout << presum[pos - 1] << endl;
        }
    }
}
