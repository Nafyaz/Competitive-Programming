#include<bits/stdc++.h>
using namespace std;
#define N 105000009

bool flag[N];
vector<int> primes;
int presz[N], preset[N];

void linsieve()
{
    int i, j;
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

int func(int p, int n)
{
    int ret = 0;
    while(p)
    {
        if((int)log2(p) + 1 <= n && (p&1))
            ret++;

        p >>= 1;
    }
    return ret;
}

int main()
{
    linsieve();
    int t, n, i, j, sz = primes.size();

    for(i = 0; i < sz; i++)
    {
        presz[i+1] = presz[i] + log2(primes[i]) + 1;
        preset[i+1] = preset[i] + __builtin_popcount(primes[i]);
    }

//    cout << presz[sz] << endl;

    cin >> t;
    while(t--)
    {
        cin >> n;
        int pos = lower_bound(presz, presz + sz + 1, n) - presz;
        cout << preset[pos-1] + func(primes[pos - 1], n - presz[pos - 1]) << endl;
    }
}
