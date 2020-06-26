#pragma GCC optimize("no-stack-protector")
#include<bits/stdc++.h>
using namespace std;
#define N 10009

int flag[N/64];
vector<int>primes;

//unsigned flag[N>>6];

#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))

//void bitWiseSieve() {
//    unsigned i, j, k;
//    unsigned LMT=sqrt(N);
//    for(i=3; i<LMT; i+=2)
//        if(!ifc(i))
//            for(j=i*i, k=i<<1; j<N; j+=k)
//                isc(j);
//}

void bitsieve()
{
    int i, j;
    for(i = 3; i * i < N; i += 2)
    {
//        if((flag[i>>6]&(1 << ((i>>1)&31))) == 0)
        if((flag[i/64]&(1 << ((i%64)/2))) == 0)
        {
            for(j = i * i; j <= N; j += 2 * i)
                flag[j/64] |= (1 << ((j%64)/2));
        }
    }

//    primes.push_back(2);
//    cout << 2 << endl;
//    int cnt = 1;
//    for(i = 3; i < N; i += 2)
//    {
//        if((flag[i/64] & (1 << ((i%64)/2))) == 0)
//            cnt++;
//        if((flag[i/64] & (1 << ((i%64)/2))) == 0 && (cnt % 100) == 1)
//            cout << i << endl;
////            primes.push_back(i);
//    }
}

int main()
{
    bitsieve();
//    bitWiseSieve();
    for(auto u : primes)
        cout << u << endl;
}
