#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005

bool flag[N];
vector<ll> primes;

ll primeCnt[N];

void sieve()
{
    ll i, j;

    flag[2] = 1;
    for(i = 3; i < N; i += 2)
        flag[i] = 1;

    for(i = 3; i * i < N; i+=2)
    {
        if(flag[i])
        {
            for(j = i*i; j < N; j += 2*i)
                flag[j] = 0;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(flag[i])
            primes.push_back(i);
    }
}


void solve()
{
    ll n;


}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    sieve();
    cout << primes.size() << "\n";
    
    ll i, j;

    // for(i = )

    // ll T;

    // memset(mnCnt, -1, sizeof mnCnt);
    // memset(ways, -1, sizeof ways);

    // cin >> T;

    // while(T--)
    // {
    //     solve();
    // }
}