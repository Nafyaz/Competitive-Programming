#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009
bool flag[N];
vector<ll> primes;

void sieve()
{
    ll i, j;
    flag[0] = flag[1] = 1;
    for(i = 4; i < N; i += 2)
        flag[i] = 1;
    for(i = 3; i * i < N; i += 2)
    {
        if(!flag[i])
        {
            for(j = i*i; j < N; j += 2 * i)
                flag[j] = 1;
        }
    }

    primes.push_back(2);
    for(i = 3; i < N; i += 2)
    {
        if(!flag[i])
            primes.push_back(i);
    }
}

ll nod(ll n)
{
    ll i, cnt, ret = 1;
    for(i = 0; primes[i] * primes[i] <= n; i++)
    {
        for(cnt = 0; n % primes[i] == 0; cnt++)
            n /= primes[i];
        ret = ret * (cnt + 1);
    }

    if(n > 1)
        ret <<= 1;

    return ret;
}

int main()
{
    sieve();
    cout << primes[primes.size() - 2];
    ll t, n, ans, i, found, d[309];
//    for(i = 0; i < 10; i++)
//        cout << i << " " << nod(i) << endl;
//    cout << endl;
//    cout << nod(2);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> d[i];
        sort(d, d+n);

//        for(i = 0; i < n; i++)
//            cout << d[i] << " ";
//        cout << endl;

        ans = d[0]*d[n-1];
        found = 1;

        for(i = 1; i < (n+1)/2 && found; i++)
        {
            if(ans != d[i]*d[n-i-1])
            {
//                cout << i << endl;
                found = 0;
            }
        }

        if(!found)
        {
            cout << -1 << endl;
            continue;
        }

        cout << (nod(ans) == n + 2? ans : -1) << endl;
    }
}
