#include<bits/stdc++.h>
using namespace std;
#define N 100009

bool flag[N];
vector<int> primes;
int pcnt[N];
void sieve()
{
    int i, j;
    for(i = 4; i < N; i += 2)
        flag[i] = 1;
    for(i = 3; i*i < N; i += 2)
    {
        if(!flag[i])
        {
            for(j = i*i; j < N; j += 2*i)
                flag[j] = 1;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes.push_back(i);
    }
}
int main()
{
    sieve();
    int n, s, i, j, x;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> s;
        for(j = 0; primes[j]*primes[j] <= s; j++)
        {
            x = 0;
            while(s%primes[j] == 0)
            {
                s /= primes[j];
                x = 1;
            }
            pcnt[primes[j]] += x;

        }
        if(s > 1)
            pcnt[s]++;
    }

    int mx = 1;
    for(i = 0; i < N; i++)
        mx = max(mx, pcnt[i]);

    cout << mx;
}
