#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define P push
#define mem(x,y) memset(x,y,sizeof(x))
#define SIZE 100000
#define pLL pair<LL,LL>

vector<int> pr;
LL flag[100005];
vector<pLL>num[100005],req;
map<vector<pLL>,LL > mp;

void sieve() {
    LL i,j;

    flag[1]=1;
    for(i=4; i<=100000; i+=2) flag[i]=1;

    for(i=3; i<=1000; i+=2) {
        if(!flag[i]) for(j=i*i; j<=SIZE; j+=2*i) flag[j]=1;
    }

    for(i=1; i<=SIZE; i++) {
        if(!flag[i])
       {
           pr.PB(i);
       }
    }

//for(i=0; i<=10; i++) cout<<pr[i]<<endl;
}

int main() {
    LL i,j,k,s,d,r,m,n;
    sieve();

    cin>>n>>k;
    for(i=1; i<=n; i++) {
        cin>>r;
        m=sqrt(r);

        for(j=0; pr[j]<=m; j++) {
            s=0;
            while(r%pr[j]==0) {
                s++;
                r/=pr[j];
            }
            s%=k;
            if(s) num[i].PB({pr[j],s});
        }

        if(r>1) num[i].PB({r,1});

    }

    s=0;
    for(i=n; i>0; i--) {
        req.clear();
        for(j=0; j<num[i].size(); j++) {
            r=k-num[i][j].second;
            req.PB({num[i][j].first,r});
            // cout<<"("<<num[i][j].first<<","<<num[i][j].second<<") ";
           // cout<<"("<<num[i][j].first<<","<<r<<")";
        }
        s+=mp[req];
        //cout<<endl<<s<<endl;
        mp[num[i]]++;
    }

    cout<<s<<endl;


}
