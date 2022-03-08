#include<bits/stdc++.h>
using namespace std;
#define hlw ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<pair<long long,string> >v[100005];
vector<pair<int,pair<int,string> > >vc[100005];
string name[100005],pname[100005];
long long D[100005],S[100005],B[100005],R[100005],freeWhen[100005];
map<string,vector<pair<long long,pair<long long,long long> > > >mp;
vector<long long>project;
vector<pair<long long,long long> >workers[100005];
map<long long,bool>taken;
int main()
{
    hlw;
    long long a,b,c,d,f,gg=0,i,j,m,n,t,mod=1e9+7,p,k;
//    freopen("input_data/f.txt","r",stdin);
//    freopen("fout.txt","w",stdout);
    cin>>n>>p;
    for(i=0; i<n; i++)
    {
        mp["ANY"].push_back({0,{0,i}});
        cin>>name[i]>>k;
        for(j=0; j<k; j++)
        {
            string s;
            long long l;
            cin>>s>>l;
            v[i].push_back({l,s});
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
            vc[i].push_back({l,{j,s}});
        }
    }
    for(i=0; i<100004; i++)
    {
        sort(vc[i].begin(),vc[i].end());
        reverse(vc[i].begin(),vc[i].end());
        sort(v[i].begin(),v[i].end());
    }
    vector<pair<long long,long long> >order,garbage;
    for(i=0; i<p; i++)
    {
        long long skillSum = 0;
        for(auto u : vc[i])
            skillSum += u.first;

        long long heur=-S[i]*S[i]+B[i]*B[i]+D[i]*D[i] + skillSum;
        order.push_back({heur,i});
    }
    sort(order.begin(),order.end());

    for(i=0; i<p; i++)
    {
        taken.clear();
        long long proj=order[i].second,serial=project.size();
        for(auto it:vc[proj])
        {
            string skill=it.second.second;
            long long lev=it.first;
            long long ind=it.second.first;
            sort(mp[skill].begin(),mp[skill].end());
            bool took=0;
            for(auto jt:mp[skill])
            {
                if(!taken[jt.second.second]&&jt.second.first>=lev&&jt.first+D[proj]-B[proj]<S[proj])
                {
                    workers[serial].push_back({ind,jt.second.second});
                    taken[jt.second.second]=1;
                    took=1;
                    break;
                }
                if(!taken[jt.second.second]&&jt.second.first+1==lev&&jt.first+D[proj]-B[proj]<S[proj])
                {
                    bool gg=0;
                    for(auto kamla:workers[serial])
                    {
                        for(auto pt:v[kamla.second])
                        {
                            if(pt.second==skill&&pt.first>=lev)
                                gg=1;
                        }
                    }
                    if(gg)
                    {
                        workers[serial].push_back({ind,jt.second.second});
                        taken[jt.second.second]=1;
                        took=1;
                        break;
                    }
                }

            }
            if(!took&&lev==1)
            {
                skill="ANY";
                for(auto jt:mp[skill])
                {
                    if(!taken[jt.second.second]&&jt.second.first>=lev&&jt.first+D[proj]-B[proj]<S[proj])
                    {
                        workers[serial].push_back({ind,jt.second.second});
                        taken[jt.second.second]=1;
                        took=1;
                        break;
                    }
                    if(!taken[jt.second.second]&&jt.second.first+1==lev&&jt.first+D[proj]-B[proj]<S[proj])
                    {
                        bool gg=0;
                        for(auto kamla:workers[serial])
                        {
                            for(auto pt:v[kamla.second])
                            {
                                if(pt.second==skill&&pt.first>=lev)
                                    gg=1;
                            }
                        }
                        if(gg)
                        {
                            workers[serial].push_back({ind,jt.second.second});
                            taken[jt.second.second]=1;
                            took=1;
                            break;
                        }
                    }

                }
            }
            if(!took)break;

        }
        if(workers[serial].size()<R[proj])
        {
            workers[serial].clear();
            continue;
        }
        project.push_back(proj);
        for(auto it:mp)
        {
            string skill=it.first;
            for(long long j=0; j<mp[skill].size(); j++)
            {
                if(taken[mp[skill][j].second.second])
                {
                    mp[skill][j].first+=D[proj];
                }
            }
        }

    }
    cout<<project.size()<<'\n';
    for(i=0; i<project.size(); i++)
    {
        sort(workers[i].begin(),workers[i].end());
        p=project[i];
        cout<<pname[p]<<'\n';
        for(j=0; j<R[p]; j++)
        {
            if(j>0)
                cout<<' ';
            cout<<name[workers[i][j].second];
        }
        cout<<'\n';
    }


    return 0;
}
