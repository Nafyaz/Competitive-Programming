#include<bits/stdc++.h>
using namespace std;
#define N 100009
bool flag[N];
vector<int> primes;

void sieve()
{
    int i, j;
    flag[0] = flag[1] = 1;
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

int nod(int x)
{
    int i, j, cnt, ret = 1;
    for(i = 0; primes[i] * primes[i] <= x; i++)
    {
        for(cnt = 0; x % primes[i] == 0; cnt++)
            x /= primes[i];

        ret *= (cnt + 1);
    }

    if(x > 1)
        ret <<= 1;
    return ret;
}

int main()
{
    sieve();

    int x, y, n, cnt = 0;

    cin >> x >> y >> n;

    for(; x <= y; x++)
    {
        if(nod(x) == n)
            cnt++;
    }

    cout << cnt;
}
