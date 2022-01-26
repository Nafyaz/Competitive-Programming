#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define all(a) a.begin(), a.end()
#define psb push_back
#define SZ(vt) (vt.size())
#define mx 300005
#define ll long long
int ara[mx];
int phi[100];
int find_phi(int n)
{
    int ret = n;
    for(int i = 2; 1ll*i*i <= n; i++)
    {
        if(n % i == 0)
        {
            ret -= ret / i;
            while( n % i == 0) n /= i;
        }
    }
    if(n > 1) ret -= ret / n;
    return ret;
}
ll mod(ll a, ll b)
{
    if( a < b) return a;
    return a % b + b;
}
ll bigmod(ll a, ll p, ll m)
{
    ll ret = 1;
    while(p)
    {
        if(p&1) ret = mod(ret * a, m);
        a = mod(a*a, m);
        p /= 2;
    }
    return ret;
}
int rec(int idx, int l, int r)
{
    if(l == r)
    {
        return ara[l];
    }
    if(phi[idx] == 1) return 1;
    return bigmod(ara[l], rec(idx+1, l+1, r), phi[idx]);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    phi[0] = m;
    for(int i = 1; ; i++)
    {
        if(phi[i] == 1) break;
        phi[i] = find_phi(phi[i-1]);
//        cout << phi[i] << " ";
    }
//    cout << endl;
    for(int i = 1; i<=n; i++)
        scanf("%d", &ara[i]);
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", rec(0, l, r) % m);
    }
    return 0;
}
