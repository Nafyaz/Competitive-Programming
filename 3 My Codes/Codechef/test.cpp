#include<bits/stdc++.h>
using namespace std;

vector<long long int>pri;

void SieveOfEratosthenes(long long int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (long  long int p=2; p<=n; p++)
        if (prime[p])
            pri.push_back(p);
}

long long int div_num(long long int n)
{
    long long int i,c,ret=1;
    for(i=0; pri[i]*pri[i]<=n; i++)
    {
        for(c=0; n%pri[i]==0; c++)
        {
            n/=pri[i];
        }
        ret*=(c+1);
    }

    if(n>1)
    {
        ret=ret<<1;
    }
    return ret;
}


void solve()
{
    long long int n;
    cin>>n;
    long long int a[10000];
    for(long long int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);


    if(n%2!=0)
    {
        long long int lala=a[n/2];
        vector<long long int>v;
        for(long long int i=0; i<n; i++)
        {
            if(a[i]==lala)
            {
                v.push_back(lala);
                v.push_back(lala);
            }
            else
            {
                v.push_back(a[i]);
            }

        }

        long long int shuru=0;
        long long int shesh=v.size()-1;
        long long int wow=v[shuru]*v[shesh];
        shuru++;
        shesh--;
        while(shuru<shesh)
        {
            if(v[shuru]*v[shesh]==wow)
            {
                shuru++;
                shesh--;

            }
            else
            {
                cout<<"No"<<endl;
                return ;
            }

        }
        long long int tata=div_num(wow);
        if(tata-1==v.size())
        {
            cout<<wow<<endl;

        }
        else
        {
            cout<<"-1"<<endl;
            return ;
        }




    }
    else
    {


        vector<long long int>v;
        for(long long int i=0; i<n; i++)
        {

            v.push_back(a[i]);
        }


        long long int shuru=0;
        long long int shesh=v.size()-1;
        long long int wow=v[shuru]*v[shesh];
        shuru++;
        shesh--;
        while(shuru<shesh)
        {
            if(v[shuru]*v[shesh]==wow)
            {
                shuru++;
                shesh--;

            }
            else
            {
                cout<<"No"<<endl;
                return ;
            }

        }

        long long int tata=div_num(wow);
        if(tata-2==v.size())
        {
            cout<<wow<<endl;

        }
        else
        {
            cout<<"-1"<<endl;
            return ;
        }



    }

}


int main()
{
    SieveOfEratosthenes(1000000);

//    cout << pri.back();

    long long int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
