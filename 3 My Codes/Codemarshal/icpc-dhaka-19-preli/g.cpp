#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000009

bool flag[N];
vector<int> primes;
ll phi[N];

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

void sievephi()
{
    ll i, j;
    for(i = 1; i < N; i++)
        phi[i] = i;

    for(auto p : primes)
    {
        for(i = p; i < N; i += p)
            phi[i] = phi[i] / p * (p - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    linsieve();
    sievephi();

    ll t, caseno = 0, n, p, i, d;
//
////    for(i = 1; i <= 25; i++)
////        cout << setw(4) << i;
////    cout << endl;
////    for(i = 1; i <= 25; i++)
////        cout << setw(4) << phi[i];
////    cout << endl;
    for(i = 2; i < N; i++)
        phi[i] += phi[i-1];
////    for(i = 1; i <= 25; i++)
////        cout << setw(4) << phi[i];

    cin >> t;
    while(t--)
    {
        cin >> n >> p;

        cout << "Case " << ++caseno << ": ";
        if(phi[n] < p)
            cout << -1 << "\n";
        else
        {
            d = lower_bound(phi+1, phi+n+1, p) - phi;
            cout << n/d << "\n";
        }
    }
}
