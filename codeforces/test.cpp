#define ll long long
#define pi acos(-1.0)
#define Go "\n"
#define Afor(i,a,b) for( i=a;i<b;i++)
#define GCD __gcd
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ll pri[101]={0};
    ll prime[101];
    ll p,q,j;
    for(p=2;p*p<=100;p++)
    {
        if(pri[p]==0)
        {
            for(q=p*p;q<=100;q+=p)
            {
                pri[q]=1;
            }
        }
    }
    for(p=2,q=0;p<=100;p++)
    {
        if(pri[p]==0)
        {
            prime[q]=p;
            q++;
        }
    }
    int t;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        ll N,i;
        cin>>N;
        cout<<"Case"<<" "<<j<<":"<<" "<<N<<" "<<"="<<" ";
        for(i=0;prime[i]<=N;i++)
        {
            ll x=N;
            ll freq=0;
            while(x/prime[i])
            {
                freq+=x/prime[i];
                x=x/prime[i];
            }
            if(i==0)
            {
                cout<<prime[i]<<" "<<"("<<freq<<")"<<" ";
            }
            else
            {
                cout<<"*"<<" "<<prime[i]<<" "<<"("<<freq<<")"<<" ";
            }
        }
        cout<<"\n";
    }



}
