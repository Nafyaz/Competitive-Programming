#include<bits/stdc++.h>
using namespace std;
#define N 500010

bool flag[N];
vector<int> primes;

void sieve()
{
    int i, j;
    for(i = 4; i < N; i += 2)
        flag[i] = 1;
    for(i = 3; i * i < N; i += 2)
    {
        if(!flag[i])
        {
            for(j = i * i; j < N; j += 2 * i)
                flag[j] = 1;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes.push_back(i);
    }
}

int SOD(int n)
{
    int i, c, p, ret = 1;
    for(i = 0; primes[i] * primes[i] <= n; i++)
    {
        p = 1;
        for(c = 0; n % primes[i] == 0; c++)
        {
            p *= primes[i];
            n /= primes[i];
        }
        ret *=  (p * primes[i] - 1) / (primes[i] - 1);
    }

    if(n > 1)
        ret *= n + 1;
    return ret;
}

int main()
{
    sieve();
    int t, i, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << SOD(n) - n << endl;
    }
}
