#include<bits/stdc++.h>
using namespace std;

int a[10000];
bool flag[1009];
vector<int> primes;

void sieve()
{
    int i, j;
    flag[0] = flag[1] = 1;
    for(i = 4; i < 1009; i += 2)
        flag[i] = 1;

    for(i = 3; i * i < 1009; i += 2)
    {
        if(!flag[i])
        {
            for(j = i * i; j < 1009; j += 2 * i)
                flag[j] = 1;
        }
    }

    for(i = 2; i < 1009; i++)
    {
        if(!flag[i])
            primes.push_back(i);
    }
}

int sod(int n)
{
    int i, ret = 1, p;
    for(i = 0; primes[i] * primes[i] <= n; i++)
    {
        for(p = 1; n % primes[i] == 0; p *= primes[i])
            n /= primes[i];
//        cout << primes[i] << " " << ret << endl;
        ret *= (p*primes[i] - 1) / (primes[i] - 1);
    }

    if(n > 1)
        ret *= n + 1;

    return ret;
}

int main()
{
//    freopen("out.txt", "w", stdout);
    int i, caseno = 0, n;
    memset(a, -1, sizeof a);

    sieve();
//
//    for(auto u : primes)
//        cout << u << endl;
//
//    sod(25);
    int mx = 0;
    for(i = 1; i <= 1000; i++)
    {
        a[sod(i)] = i;
//        cout << sod(i) << " " << i << endl;
//        mx = max(mx, sod(i));
    }
//    cout << mx << endl;

    while(1)
    {
        cin >> n;
        if(!n)
            break;
        cout << "Case " << ++caseno << ": " << a[n] << endl;
    }
}
