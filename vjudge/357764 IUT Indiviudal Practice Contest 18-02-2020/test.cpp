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

ll Inverse_Modulo(ll a,ll m)
{
    return BigMod(a,m-2,m);
}


ll func(ll r, ll c)
{
    ll i, ret = 0, x = 1;
    for(i = 1; i <= c+1; i++)
    {
        x = ((x*(r+i))%mod * Inverse_Modulo(i, mod))%mod;
        ret = (ret + x)%mod;
    }

    cout << r << " " << c << " " << ret << endl;
    return ret;
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

    cout << ans;
}
