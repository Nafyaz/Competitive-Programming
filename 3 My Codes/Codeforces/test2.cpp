#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector <int>primes;

void sieve()
{
    bool isprime[33000];
    for(int i =0; i<=32000; i++)
        isprime[i]=true;

    for(int i=3; i*i<=32000; i+=2)
    {
        if(isprime[i])
        {
            for(int j=i*i; j<=32000; j+=i) // now we are going to mark all the multiples
            {
                isprime[j]=false;
            }
        }
    }
    primes.push_back(2); // we left 2 out so need to push first
    for(int i=3; i<32000; i+=2)
    {
        if(isprime[i])
            primes.push_back(i);
    }
}
void segsieve(ll l, ll r)
{
    bool segprime[r-l+1];
    for(int i = 0; i<=r-l+1; i++)
        segprime[i]=true;
    if(l==1)
        segprime[0]=false;

    for(int i=0; primes[i]*primes[i]<=r; i++) // eitate ki jani somossa hosse
    {

        ll curprime=primes[i];
        ll base = (l/curprime)*curprime;

        if(base<l)
        {

            base=base+curprime;
        }
        for(ll j=base; j<=r; j+=curprime)
        {
            segprime[l-j]=false;
        }
        if(base==curprime)
            segprime[base-l]=true;

    }
    for(int i=0; i<=r-l+1; i++)
        if(segprime[i])
            cout<<i+l<<endl;
    puts("");
}
int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll l, r;
        cin>>l>>r;
        segsieve(l, r);
    }
}
