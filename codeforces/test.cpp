#define GODSPEED ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define f(i,x,n) for(i=x;i<n;i++)
#define rf(i,x,n) for(i=n;i>x;i--)
#define ll long long
#define GCD(a,b) __gcd(a,b);
#define adios return 0;


#include <bits/stdc++.h>
using namespace std;

int main()
{
    GODSPEED;
    ll t,n,a,b,c,d,s=0,i,j,flag;
    string x;
    while(getline(cin,x))
    {
        n=x.size();
        string a1="`";
        string a2="'";
        f(i,0,n)
        {
            if(x[i]=='"')
            {
                s++;
                if(s%2==1)
                {
                    x[i]=96;
                    x.insert(i,a1);
                }
                else if(s%2==0)
                {
                    x[i]=39;
                    x.insert(i,a2);
                }
            }
        }

        cout<<x<<endl;
    }
    adios;
}
/*
"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"
*/
