/*
SHERAJUL ARIFIN
Dept. of CSE,
IUT.
*/

#define GODSPEED ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define f(i,x,n) for(i=x;i<n;i++)
#define rf(i,x,n) for(i=n;i>x;i--)
#define ll long long
#define gcd(a,b) __gcd(a,b);
#define adios return 0;

#include <bits/stdc++.h>
using  namespace std;

int main()
{
    GODSPEED;
    ll t,a,b,c,d,s=0,i,n,mx,mn;
    cin>>a>>b;
    mx=((a-b+1)*(a-b))/2;
    if(b==1)
        mn=mx;
    else if(a==b)
        mn=mx=0;
    else
    {
        c=a/b;
        d=a%b;
        mn=(((c)*(c-1))/2)*b + d*c;
    }
    cout<<mn<<" "<<mx;


    adios;
}
