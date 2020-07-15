#include<bits/stdc++.h>
using namespace std;
#define N 1000009
bool flag[N];
vector<int> primes;

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

int bigmod(int a, int p)
{
    int ret = 1;
    while(p)
    {
        if(p&1)
            ret = (ret * a) % 10;
        a = (a * a) % 10;
        p >>= 1;
    }

    return ret;
}

int main()
{
    linsieve();

    int i, j, n, cnt;

    while(1)
    {
        cin >> n;
        if(!n)
            break;

        int ans = bigmod(2, (int)log2(n) - (int)(log(n)/log(5)));
        for(i = 0; primes[i] <= n; i++)
        {
            if(primes[i] != 2 && primes[i] != 5)
                ans = (ans * bigmod(primes[i], (log(n)/log(primes[i])))) % 10;
        }

        cout << ans << endl;
    }
}
