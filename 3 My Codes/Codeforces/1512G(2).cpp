#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000007

int leastFactor[N];
vector<int> primes;
int reverseSod[N];

void linSieve()
{
    int i, j;

    for(i = 2; i < N; i++)
    {
        if(leastFactor[i] == 0)
        {
            leastFactor[i] = i;
            primes.push_back(i);

        }
        for(j = 0; j < (int)primes.size() && primes[j] <= leastFactor[i] && i*primes[j] < N; j++)
            leastFactor[i*primes[j]] = primes[j];
    }
}

ll SOD(ll n) //only this function is long long
{
    ll lf, c, p, ret = 1;

    while(n > 1)
    {
        lf = leastFactor[n];
        p = 1;

        for(c = 0; n%lf == 0; c++)
        {
            n /= lf;
            p *= lf;
        }

        ret *= (p*lf - 1)/(lf - 1);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    linSieve();

    int i, sod, t, c;

    memset(reverseSod, -1, sizeof reverseSod);
    for(i = 1; i < N; i++)
    {
        sod = SOD(i);

        if(sod < N && reverseSod[sod] == -1)
            reverseSod[sod] = i;
    }

    cin >> t;

    while(t--)
    {
        cin >> c;
        cout << reverseSod[c] << "\n";
    }
}
