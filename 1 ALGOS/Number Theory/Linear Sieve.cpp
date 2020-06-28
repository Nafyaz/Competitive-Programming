#include<bits/stdc++.h>
using namespace std;
#define N 10000009

bool flag[N];
vector<int> primes;
void linsieve()
{
    int i, j;
    for(i = 2; i < N; i++)
    {
        if (!flag[i])
            primes.push_back(i);

        for(j = 0; j < primes.size() && i*primes[j] < N; j++)
        {
            flag[i * primes[j]] = 1;
            if(i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    linsieve();

    int mx = 0;
    for(int i = 1; i < primes.size(); i++)
        mx = max(mx, primes[i] - primes[i-1]);
    cout << mx;
}
