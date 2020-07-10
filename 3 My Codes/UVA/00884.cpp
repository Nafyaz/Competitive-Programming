#include<bits/stdc++.h>
using namespace std;
#define N 1000009

int ans[N];
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

int func(int n)
{
    int i, j, c, ret = 0;
    for(i = 0; primes[i] * primes[i] <= n; i++)
    {
        for(j = 0; n%primes[i] == 0; j++)
            n /= primes[i];
        ret += j;
    }

    if(n > 1)
        ret++;

    return ret;
}

int main()
{
    linsieve();
    int n, i;

    for(i = 2; i < N; i++)
        ans[i] = ans[i-1] + func(i);

    while(cin >> n)
        cout << ans[n] << endl;
}
