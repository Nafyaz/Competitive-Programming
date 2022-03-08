#include<bits/stdc++.h>
using namespace std;
#define hlw ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<pair<string,long long> >v[100005],vc[100005];
string name[100005],pname[100005];
long long D[100005],S[100005],B[100005],R[100005],freeWhen[100005];
map<string,vector<pair<long long,pair<long long,long long> > > >mp;
vector<long long>project,workers[100005];
map<long long,bool>taken;
int main()
{
    hlw;
    long long a,b,c,d,f,gg=0,i,j,m,n,t,mod=1e9+7,p,k;
    freopen("input_data/b.txt","r",stdin);
    freopen("bout.txt","w",stdout);
    cin>>n>>p;
    for(i=0; i<n; i++)
    {
        cin>>name[i]>>k;
        for(j=0; j<k; j++)
        {
            string s;
            long long l;
            cin>>s>>l;
            v[i].push_back({s,l});
            mp[s].push_back({0,{l,i}});
        }
    }

    for(i=0; i<p; i++)
    {
        cin>>pname[i]>>D[i]>>S[i]>>B[i]>>R[i];
        for(j=0; j<R[i]; j++)
        {
            string s;
            long long l;
            cin>>s>>l;
            vc[i].push_back({s,l});
        }
    }
    vector<pair<long long,long long> >order,garbage;
    for(i=0; i<p; i++)
    {
        long long heur=-S[i]*S[i]+B[i]*B[i]+D[i]*D[i];
        order.push_back({heur,i});
    }
    sort(order.begin(),order.end());

    for(i=0; i<p; i++)
    {
        taken.clear();
        long long proj=order[i].second,serial=project.size();
        for(auto it:vc[proj]){
            string skill=it.first;
            long long lev=it.second;
            sort(mp[skill].begin(),mp[skill].end());
            for(auto jt:mp[skill]){
                if(!taken[jt.second.second]&&jt.second.first>=lev&&jt.first+D[proj]-B[proj]<S[proj]){
                    workers[serial].push_back(jt.second.second);
                    taken[jt.second.second]=1;
                    break;
                }

            }
        }
        if(workers[serial].size()<R[proj]){
            workers[serial].clear();
            continue;
        }
        project.push_back(proj);
        for(auto it:vc[proj]){
            string skill=it.first;
            long long lev=it.second;
            for(long long j=0;j<mp[skill].size();j++){
                if(taken[mp[skill][j].second.second]){
                   mp[skill][j].first+=D[proj];
                }
            }
        }

    }
    cout<<project.size()<<'\n';
    for(i=0;i<project.size();i++){
        p=project[i];
        cout<<pname[p]<<'\n';
        for(j=0;j<R[p];j++){
            if(j>0)cout<<' ';
            cout<<name[workers[i][j]];
        }
        cout<<'\n';
    }


    return 0;
}


