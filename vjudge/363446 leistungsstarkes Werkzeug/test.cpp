#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll BigMod(ll a,ll b,ll c)
{
    ll  R=1;
    while(b>0)
    {
        if(b%2==1)
        {
            R=(R*a)%c;
        }
        b=b/2;
        a=(a*a)%c;
    }
    return R;
}
int main()
{
    ll a,b,c,m;

    while(cin>>a>>b>>c)
    {
        m=BigMod(a,b,c);
        cout<<m<<endl;

    }
    return 0;
}
