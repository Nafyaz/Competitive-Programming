//Problem E K-Inversions CF Gym

#include<bits/stdc++.h>
using namespace std;

#define MAX             100005
#define MOD             1000000007
#define eps             1e-6
int fx[] =              {1,-1,0,0};
int fy[] =              {0,0,1,-1};

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);
#define fRead           freopen("in.txt","r",stdin);
#define fWrite          freopen ("out.txt","w",stdout);

#define ll              long long
#define ull             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define all(a)          a.begin(),a.end()

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))

#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define IT(it,x)	    for(it=x.begin();it!=x.end();it++)

#define MEM(a,x)        memset(a,x,sizeof(a))
#define TC              int t;cin >> t;FOR(tc,1,t)
#define ABS(x)          ((x)<0?-(x):(x))
#define SQ(x)           ((x)*(x))
#define SP(x)           fixed << setprecision(x)


#define Make(x,p)       (x | (1<<p))
#define DeMake(x,p)     (x & ~(1<<p))
#define Check(x,p)      (x & (1<<p))
#define popcount(x)     __builtin_popcount(x)

typedef complex<double> base;

void fft(vector<base> & a, bool invert)
{
    int n = (int)a.size();

    for (int i = 1, j = 0; i<n; ++i)
    {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1)
    {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (int i = 0; i<n; i += len)
        {
            base w(1);
            for (int j = 0; j<len / 2; ++j)
            {
                base u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i = 0; i<n; ++i)
            a[i] /= n;
}

vector<ll> Mul(vector<ll>& a, vector<ll>& b)
{
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < max(a.size(), b.size()))
        n <<= 1;
    n <<= 1;
    fa.resize(n), fb.resize(n);

    fft(fa, false), fft(fb, false);
    for (int i = 0; i<n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> res;
    res.resize(n);
    for (int i = 0; i<n; ++i)
        res[i] = round(fa[i].real());
    return res;
}
vector<ll>v1,v2,v;
int main()
{
    string str;
    cin >> str;
    int n=str.size();
    v2.resize(n+1);
    //n degree Polynomial division: coefficient of x^i is replaced with coefficient of x^(n-i).
    REP(i,n)
    {
        if(str[i]=='A'){
            v1.pb(1);
            v2[n-i]=0;
        }
        else
        {
            v1.pb(0);
            v2[n-i]=1;
        }
    }
    v=Mul(v1,v2);
    //x^(i-j) starts from n+1 ends at 2*n-1
    for(int i=n+1;i<n*2;i++) cout << v[i] << '\n';
}
