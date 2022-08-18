//CS Academy : Random Nim Generator

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define bitwiseXOR 1
//#define bitwiseAND 2
//#define bitwiseOR 3
const LL MOD = 30011;

LL BigMod(LL b,LL p)
{
    LL ret=1;
    while(p > 0){
        if(p % 2 == 1){
            ret=(ret*b)%MOD;
        }
        p = p/2;
        b=(b*b)%MOD;
    }
    return ret%MOD;
}

void FWHT(vector< LL >&p, bool inverse)
{
    LL n = p.size();
    assert((n&(n-1))==0);

    for (LL len = 1; 2*len <= n; len <<= 1) {
        for (LL i = 0; i < n; i += len+len) {
            for (LL j = 0; j < len; j++) {
                LL u = p[i+j];
                LL v = p[i+len+j];

                #ifdef bitwiseXOR
                p[i+j] = (u+v)%MOD;
                p[i+len+j] = (u-v+MOD)%MOD;
                #endif // bitwiseXOR

                #ifdef bitwiseAND
                if (!inverse) {
                    p[i+j] = v % MOD;
                    p[i+len+j] = (u+v) % MOD;
                } else {
                    p[i+j] = (-u+v) % MOD;
                    p[i+len+j] = u % MOD;
                }
                #endif // bitwiseAND

                #ifdef bitwiseOR
                if (!inverse) {
                    p[i+j] = u+v;
                    p[i+len+j] = u;
                } else {
                    p[i+j] = v;
                    p[i+len+j] = u-v;
                }
                #endif // bitwiseOR
            }
        }
    }

    #ifdef bitwiseXOR
    if (inverse) {
        LL val=BigMod(n,MOD-2); //Option 2: Exclude
        for (LL i = 0; i < n; i++) {
            //assert(p[i]%n==0); //Option 2: Include
            p[i] = (p[i]*val)%MOD; //Option 2: p[i]/=n;
        }
    }
    #endif // bitwiseXOR
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL n ,k;
    cin >> n >> k;
    int len=1;
    while(len<=k) len <<= 1;
    vector<LL>a(len,0);
    for(int i=0;i<=k;i++) a[i]=1;
    FWHT(a,false);
    for(int i=0;i<len;i++) a[i]=BigMod(a[i],n);
    FWHT(a,true);
    LL ans=0;
    for(int i=1;i<a.size();i++) ans=(ans+a[i])%MOD;
    cout << ans%MOD;
}
