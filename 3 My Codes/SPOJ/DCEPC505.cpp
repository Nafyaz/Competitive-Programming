#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 20000009

bitset<N> flag, check;
vector<ll> primes, ans;

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

int main()
{
    linsieve();
    ll t, n, i, j;

    for(i = 0; i < primes.size(); i++)
    {
        for(j = i+1; j < primes.size() && primes[i] * primes[j] < N; j++)
        {
//            if(i == 4790)
//                cout << j << " " << primes[j] << " " << primes[i] * primes[j] << endl;
            check[primes[i] * primes[j]] = 1;
        }
    }

    for(i = 0; i < N; i++)
    {
        if(check[i])
        {
//            cout << i << endl;
            ans.push_back(i);
        }
    }

    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << ans[n-1] << endl;
    }
}
