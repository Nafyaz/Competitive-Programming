//https://toph.co/p/play-the-lottery

#include <bits/stdc++.h>

using namespace std;

#define LL      long long
#define pii     pair<LL,LL>

const LL N= 1<<18;
const LL MOD=786433;

vector<LL>P[N];

LL rev[N],w[N|1],a[N],b[N],inv_n,g;

LL Pow(LL b,LL p){
    LL ret=1;
    while(p){
        if(p & 1) ret=(ret*b)%MOD;
        b=(b*b)%MOD;
        p>>=1;
    }
    return ret;
}

LL primitive_root(LL p){
    vector<LL>factor;
    LL phi = p-1,n=phi;

    for(LL i=2;i*i<=n;i++){
        if(n%i) continue;
        factor.emplace_back(i);
        while(n%i==0) n/=i;
    }

    if(n>1) factor.emplace_back(n);
    for(LL res=2;res<=p;res++){
        bool ok=true;
        for(LL i=0;i<factor.size() && ok;i++) ok &= Pow(res,phi/factor[i]) != 1;
        if(ok) return res;
    }
    return -1;
}

void prepare(LL n){
    LL sz=abs(31-__builtin_clz(n));
    LL r=Pow(g,(MOD-1)/n);
    inv_n=Pow(n,MOD-2);
    w[0]=w[n]=1;
    for(LL i=1;i<n;i++) w[i]= (w[i-1]*r)%MOD;
    for(LL i=1;i<n;i++) rev[i]=(rev[i>>1]>>1) | ((i & 1)<<(sz-1));
}

void NTT(LL *a,LL n,LL dir=0)
{
    for(LL i=1;i<n-1;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    for(LL m=2;m<=n;m <<= 1) {
        for(LL i=0;i<n;i+=m){
            for(LL j=0;j< (m>>1);j++){
                LL &u=a[i+j],&v=a[i+j+(m>>1)];
                LL t=v*w[dir ? n-n/m*j:n/m*j]%MOD;
                v=u-t<0?u-t+MOD:u-t;
                u=u+t>=MOD?u+t-MOD:u+t;
            }
        }
    }
    if(dir) for(LL i=0;i<n;i++) a[i]=(inv_n*a[i])%MOD;
}

vector<LL> mul(vector<LL>p,vector<LL>q)
{
    LL n=p.size(),m=q.size();
    LL t=n+m-1,sz=1;
    while(sz<t) sz <<= 1;
    prepare(sz);

    for(LL i=0;i<n;i++) a[i]=p[i];
    for(LL i=0;i<m;i++) b[i]=q[i];

    for(LL i=n;i<sz;i++) a[i]=0;
    for(LL i=m;i<sz;i++) b[i]=0;

    NTT(a,sz);
    NTT(b,sz);
    for(LL i=0;i<sz;i++) a[i]=(a[i]*b[i])%MOD;
    NTT(a,sz,1);

    vector<LL> c(a,a+sz);
    while(c.size() && c.back()==0) c.pop_back();
    return c;
}

vector<LL> solve(LL l,LL r)
{
    if(l==r) return P[l];
    LL m=(l+r)/2;
    return mul(solve(l,m),solve(m+1,r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL m;
    cin >> m;
    for(LL i=1;i<=m;i++)
    {
        LL num;
        cin >> num;
        vector<pii>v;
        LL mx=0;
        while(num--)
        {
            LL typ,cnt;
            cin >> typ >> cnt;
            v.emplace_back(typ,cnt);
            mx=max(mx,typ);
        }
        P[i].resize(mx+1);
        for(pii p:v) P[i][p.first]=p.second;
    }
    g=primitive_root(MOD);
    vector<LL>c=solve(1,m);
    for(LL i=0;i<c.size();i++){
        if(c[i]){
            cout << i << ' ' << c[i] << '\n';
        }
    }
}
