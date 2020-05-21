#include<bits/stdc++.h>
using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define LL long long
#define MX 100000
#define MOD 1000000007



    string s[MX];

int main()
{
    map<char,int>mp;
    char c;
    int cnt=0;
    while(cin>>s[cnt++])
        if(s[cnt-1]=="#")
            break;

    for(int i=0;i<20;i++)
        for(int j=0;j<cnt-1;j++)
            if(i<s[j].length())
                {
                    c=s[j][i];
                    if(mp[c]!=1)
                    {
                        cout<<c;
                        mp[c]=1;
                    }
                }
    cout<<endl;

return 0;
}
