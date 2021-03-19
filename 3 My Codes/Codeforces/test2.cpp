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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double x,y,x1,y1; //points
    scanf("%lf %lf %lf %lf",&x,&y,&x1,&y1);
    double p=(x-x1)*(x-x1);
    //cout<<p<<"\n";
    printf("%lf \n",p);
    double q=(y-y1)*(y-y1);
    //cout<<q<<"\n";
    printf("%lf \n",q);
    double r=sqrt(p+q);
    printf("%lf",r);

}
