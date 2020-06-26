#include<bits/stdc++.h>
using namespace std;
#define N 1009

int cnt[N], csum[N];
bool flag[N];
vector<int> primes;

void sieve()
{
    int i, j;
    for(i = 4; i < N; i+=2)
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
        if(flag[i] == 0)
            primes.push_back(i);
    }
}

int main()
{
    sieve();
    int n, k, i;

    for(i = 1; i < primes.size(); i++)
    {
        if(primes[i] + primes[i-1] + 1 < N && flag[primes[i] + primes[i-1] + 1] == 0)
            cnt[primes[i] + primes[i-1] + 1] = 1;
    }

//    for(i = 0; i < 50; i++)
//        cout << primes[i] << endl;

    for(i = 1; i < N; i++)
        csum[i] = csum[i-1] + cnt[i];

    cin >> n >> k;

    cout << (csum[n] >= k? "YES" : "NO");

}
