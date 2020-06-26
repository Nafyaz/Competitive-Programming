#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009
bool flag[N];
vector<ll> primes;
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

int main()
{
//    sieve();
//    freopen("out.txt", "w", stdout);
//    cout << primes.size() << endl;
//    for(auto u : primes)
//        cout << u << " ";

    int i;
    string s, t;
    for(i = 0; i < 1000000; i++)
    {
        if(i%100000 == 0)
            cout << i << endl;
        s = s + '0';
    }
    for(i = 0; i < 1000000; i++)
        t = t + '0';
    cout << s.size() + t.size();
}
