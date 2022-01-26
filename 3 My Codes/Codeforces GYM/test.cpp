//The things which seem to be hard,
//are not hard at all.You just need a little bit of practise.
//I was wrong, something are only achievable if you are gifted
#include <bits/stdc++.h>
#define lld long long int
#define pb push_back
#define in insert
#define mod 1000000007
#define pi 3.14159265358979
#define inf 1000000000000000007

using namespace std;
using namespace std::chrono;

lld powf(lld bse, lld co)
{
    lld mul = 1;
    for (lld i = 0; i < co; i++)
    {
        mul *= bse;
    }
    return mul;
}

vector<lld>fact(1007,0);

void init_fact()
{
    fact[0]=1;
    for(lld i=1; i<1007; i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
}

long long inv(long long a, long long b) //a^-1 mod b
{
    return 1<a ? b - inv(b%a,a)*b/a : 1;
}

vector<bool>prime(10000077,true);

void init_prime()
{
    prime[0]=prime[1]=false;

    for(lld i=2; i*i<10000077; i++)
    {
        if(prime[i])
        {
            for(lld j=i; i*j<10000077; j++)
            {
                prime[i*j]=false;
            }
        }
    }
}

void solve()
{
    lld n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<lld>leftmin(n+1),leftmax(n+1),rightmin(n+2),rightmax(n+2),leftsum(n+1);
    leftmin[0]=0;
    leftmax[0]=0;
    rightmin[n+1]=0;
    rightmax[n+1]=0;
    leftsum[0]=0;

    for(lld i=1; i<=n; i++)
    {
        if(s[i-1]=='+')
            leftsum[i]=leftsum[i-1]+1;
        else
            leftsum[i]=leftsum[i-1]-1;
        leftmin[i]=min(leftmin[i-1],leftsum[i]);
        leftmax[i]=max(leftmax[i-1],leftsum[i]);
    }

    for(lld i=n; i>=1; i--)
    {
        if(s[i-1]=='+')
        {
            rightmin[i]=min(rightmin[i+1]+1,(lld)0);
            rightmax[i]=max(rightmax[i+1]+1,(lld)0);
        }
        else
        {
            rightmin[i]=min(rightmin[i+1]-1,(lld)0);
            rightmax[i]=max(rightmax[i+1]-1,(lld)0);
        }

    }

    for(lld i = 0; i <= n; i++)
        cout << rightmin[i] << " " << rightmax[i] << "\n";

    while(q--)
    {
        lld l,r;
        cin>>l>>r;

        lld mn=min(leftmin[l-1],leftsum[l-1]+rightmin[r+1]);
        lld mx=max(leftmax[l-1],leftsum[l-1]+rightmax[r+1]);
        cout<<mx-mn+1<<"\n";
    }
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    //freopen("test1.txt","r",stdin);
    //freopen("test_algo.txt","w",stdout);
    init_fact();

    lld t=1;
    cin>>t;
    while(t--)
    {
        //auto start=high_resolution_clock::now();
        //init();

        solve();

        //auto stop=high_resolution_clock::now();

        //auto duration=duration_cast<microseconds>(stop-start);
        //cout<<duration.count()<<"\n";
    }

    return 0;
}
