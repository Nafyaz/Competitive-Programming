#include<bits/stdc++.h>
using namespace std;
#define N 1300009

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

    int n;
    while(1)
    {
        cin >> n;
        if(!n)
            break;
        if(!flag[n])
            cout << 0 << endl;
        else
        {
            int pos = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
            cout << primes[pos] - primes[pos-1] << endl;
        }
    }
}
