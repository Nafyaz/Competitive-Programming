#include<bits/stdc++.h>
using namespace std;
#define N 100009

int flag[N/64];
vector<int>primes;

void bitsieve()
{
    int i, j;
    for(i = 3; i * i < N; i += 2)
    {
        if((flag[i/64]&(1 << ((i%64)/2))) == 0)
        {
            for(j = i * i; j <= N; j += 2 * i)
                flag[j/64] |= (1 << ((j%64)/2));
        }
    }

    primes.push_back(2);
//    cout << 2 << endl;
    int cnt = 1;
    for(i = 3; i < N; i += 2)
    {
        if((flag[i/64] & (1 << ((i%64)/2))) == 0)
            cnt++;
        if((flag[i/64] & (1 << ((i%64)/2))) == 0 && (cnt % 100) == 1)
            primes.push_back(i);
//            cout << i << endl;
    }
}

int main()
{
    bitsieve();
    for(auto u : primes)
        cout << u << endl;
}
