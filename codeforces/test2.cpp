    #include<bits/stdc++.h>
    using namespace std;

    map<string,int>mapp;
    map<string,int>::iterator it;
    list<string>l;
    list<string>:: iterator a;

    int main(void)
    {
        int n,m,ans=0,i,j;
        cin >> n >> m;  getchar();
        string s[n],x;
        for(i=0;i<n;i++)
        {
            cin >> s[i] ;
            x=s[i];
            reverse(x.begin(),x.end());
            if(s[i]==x)
            {
                if(mapp.find(s[i])==mapp.end())mapp[s[i]]=1;
                else mapp[s[i]]++;
            }
        }

        for(it=mapp.begin();it!=mapp.end();it++)
        {
            if(it->second==1){ans=m;l.push_back(it->first);break;}
        }

        for(i=0;i<n-1;i++)
        {
            if(s[i].empty());
            else
            {
                for(j=i+1;j<n;j++)
                {
                    x=s[j];
                    reverse(x.begin(),x.end());
                    if(s[i]==x)
                    {
                        l.push_front(s[i]);
                        s[i]="";
                        l.push_back(s[j]);
                        s[j]="";
                        ans=ans+2*m;
                        break;
                    }
                }
            }
        }

        cout << ans << endl;
        for(a=l.begin();a!=l.end();a++)
        {
            cout << *a;
        }

        return 0;
    }

