#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

ll mod = 1000000007;

ll mulmod(ll a, ll b)
{
    if(b == 0)
        return 0;

    ll x = 0;
    if(b&1)
        x = a;
    ll y = mulmod(a, b/2);

    return ((y+y)%mod + x)%mod;
}

ll BigMod(ll B,ll P,ll M)
{
	ll R=1;
	while(P>0)
	{
		if(P%2==1)
		{
			R=(R*B)%M;
		}
		P/=2;
		B=(B*B)%M;
	}
	return R;
}

ll Extended_Euclidean(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }

    ll d;

    d=Extended_Euclidean(b,a%b,y,x);
    y=y-(a/b)*x;

    return d;
}
ll Inverse_Modulo(ll a,ll m)
{
    ll x,y,d;

    d=Extended_Euclidean(a,m,x,y);

    if(d==1)    return (x+m)%m; //Solution Exists
    return -1;  //No Solution
}



ll func(ll r, ll c)
{
    ll i, ret = 0, x = 1;

    ll y = 1;
    for(i = r+c+2; i >= c+2; i--)
        y = (y*i)%mod;

    for(i = 2; i <= r+1; i++)
        x = (x*i)%mod;
//        y = (y*Inverse_Modulo(i, mod))%mod;

//    cout << r << " " << c << " " << y << " " << x << " " << Inverse_Modulo(x, mod) << endl;

    return mulmod(y, Inverse_Modulo(x, mod)) - 1;
}

//void nCr(ll n, ll r)
//{
//    if(r == 0)
//        return 1;
//    if(r == 1)
//        return n%mod;
//    return (nCr(n-1, r-1) + nCr(n-1, r))%mod;
//}


int main()
{
    ll r1, r2, c1, c2, i, ans = 0, x;
    cin >> r1 >> c1 >> r2 >> c2;

    ans = (ans + func(r2, c2))%mod;
    ans = (ans - func(r2, c1-1))%mod;
    ans = (ans - func(r1-1, c2))%mod;
    ans = (ans + func(r1-1, c1-1))%mod;
    ans = (ans + mod)%mod;

    cout << ans;
}
