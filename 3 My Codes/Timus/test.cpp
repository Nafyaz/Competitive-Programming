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
   double n, r;
   cin>>n>>r;
   double x,y,s=0;
   double x1,y1;
   cin>>x1>>y1;
   double x2=x1,y2=y1;
   for(int i=1;i<=(n-1);i++)
   {
        cin>>x>>y;
        double p=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
        s=s+p;

        x1=x;
        y1=y;
   }
    s=s+sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
    s = s+ 2*pi*r;
   cout<<fixed<<setprecision(2)<< s <<"\n";
}
