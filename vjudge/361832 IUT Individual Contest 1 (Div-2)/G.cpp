#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v;

long long x[500005],y[500005],sum[500005],sz[500005];
long long root(long long p)
{
    return p == x[p] ? p : x[p] = root(x[p]);
}
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    while(cin>>n>>m)
    {
        for(i=0; i<=n; i++)
        {
            sum[i]=i;
            sum[i+n]=i;
            x[i]=i+n;
            x[i+n]=i+n;
            sz[i]=1;
            sz[i+n]=1;
        }
        for(i=0; i<m; i++)
        {
            cin>>g;
            if(g==1)
            {
                cin>>a>>b;
                p=root(a);
                q=root(b);
                if(p==q)continue;
				x[p]=q;
				sum[q]+=sum[p];
				sz[q]+=sz[p];

            }
            else if(g==2)
            {
                cin>>a>>b;
                p=root(a);
                q=root(b);
                if(p==q)continue;
                x[a]=q;
				sum[q]+=a;
				sum[p]-=a;
				sz[q]+=1;
				sz[p]-=1;

            }
            else
            {
                cin>>a;
                p=root(a);
                cout<<sz[p]<<' '<<sum[p]<<'\n';


            }
        }


    }
    return 0;
}
