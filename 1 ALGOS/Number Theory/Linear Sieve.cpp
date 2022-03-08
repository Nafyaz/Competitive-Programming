#include<bits/stdc++.h>
using namespace std;
#define N 10000007

int leastFactor[N];
bool flag[N];
vector<int> primes;
void linSieve()
{
    int i, j;
    for(i = 2; i < N; i++)
    {
        if (!flag[i])
            primes.push_back(i);

        for(j = 0; j < (int)primes.size() && i*primes[j] < N; j++)
        {
            flag[i * primes[j]] = 1;
            if(i % primes[j] == 0)
                break;
        }
    }
}

void linSieve2()
{
    int i, j;
    for (i = 2; i < N; ++i)
    {
        if (leastFactor[i] == 0)
        {
            leastFactor[i] = i;
            primes.push_back(i);
        }
        for (j = 0; j < (int)primes.size() && primes[j] <= leastFactor[i] && i*primes[j] < N; ++j)
        {
            leastFactor[i * primes[j]] = primes[j];
        }
    }
}

int main()
{
    linSieve();

    int mx = 0;
//    for(int i = 1; i < primes.size(); i++)
//        mx = max(mx, primes[i] - primes[i-1]);

    for(int i = 0; i < 10; i++)
        cout << primes[i] << " ";
}
