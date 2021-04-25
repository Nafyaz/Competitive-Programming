#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n;
ll cap[750][750], par[750];
vector<ll> adj[750];
vector<string> allnames[30];
map<string, int> mp;
string rev_mp[750];

ll bfs(ll s, ll t)
{
    memset(par, -1, sizeof par);
    par[s] = -2;

    queue<pair<ll, ll>> q;
    q.push({s, INT_MAX});

    while(!q.empty())
    {
        ll cur = q.front().ff;
        ll flow = q.front().ss;
        q.pop();

        for(auto next : adj[cur])
        {
            if(par[next] == -1 && cap[cur][next])
            {
                par[next] = cur;
                ll new_flow = min(flow, cap[cur][next]);
                if(next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t)
{
    ll flow = 0, new_flow;

    while(new_flow = bfs(s, t))
    {
//        cout << new_flow << "\n";
        flow += new_flow;

        ll prev, cur;
        for(cur = t; cur != s; cur = prev)
        {
            prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
        }
    }

    return flow;
}

int main()
{
    ll T, caseno = 0, i, j, k, s, t, namecnt;
    string name;

    s = 1;
    t = 2;



    cin >> T;

    while(T--)
    {
        cin >> n;

        //Clear Everything
        mp.clear();
        memset(cap, 0, sizeof cap);
        for(i = 0; i < 750; i++)
        {
            adj[i].clear();
            rev_mp[i] = "";
        }
        for(i = 0; i < 30; i++)
            allnames[i].clear();
        //Cleared Everything

        for(i = 'a'; i <= 'z'; i++)
        {
            string tempi;
            tempi = char(i);
            mp[tempi] = i-'a'+3;
            rev_mp[i-'a'+3] = tempi;
        }

        namecnt = i-'a'+3;

        for(i = 0; i < n; i++)
        {
            cin >> k;
            for(j = 0; j < k; j++)
            {
                cin >> name;

                for(auto& u : name)
                    u = tolower(u);
                name[0] = toupper(name[0]);

                allnames[i].push_back(name);
                mp[name] = namecnt;
                rev_mp[namecnt] = name;
                namecnt++;
            }
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < allnames[i].size(); j++)
            {
                name = allnames[i][j];

                char c = name[0] - 'A' + 'a';
                string tempc;
                tempc = c;
                adj[mp[tempc]].push_back(mp[name]);
                adj[mp[name]].push_back(mp[tempc]);
                cap[mp[tempc]][mp[name]] += 1;
//                cap[mp[name]][mp[tempc]] += 1;

                if(!cap[s][mp[tempc]])
                {
                    adj[s].push_back(mp[tempc]);
                    adj[mp[tempc]].push_back(s);
                    cap[s][mp[tempc]] += 1;
//                    cap[mp[tempc]][s] += 1;
                }

                adj[mp[name]].push_back(namecnt);
                adj[namecnt].push_back(mp[name]);
                cap[mp[name]][namecnt] += 1;
//                cap[namecnt][mp[name]] += 1;
            }

            adj[namecnt].push_back(t);
            adj[t].push_back(namecnt);
            cap[namecnt][t] += 1;
//            cap[t][namecnt] += 1;

            namecnt++;
        }

//        for(i = 0; i < 45; i++)
//        {
//            cout << "adj[" << i << "]: ";
//            for(auto u : adj[i])
//            {
//                cout << u << " ";
//            }
//            cout << "\n";
//        }

//        for(i = 0; i < n; i++)
//        {
//            for(auto u : allnames[i])
//                cout << u << " ";
//            cout << "\n";
//        }

        maxflow(s, t);

        cout << "Case #" << ++caseno << ":\n";
        for(i = 'a'; i <= 'z'; i++)
        {
            string tempi;
            tempi = char(i);
            ll cur = mp[tempi];

//            cout << cur << "\n";
            for(auto next : adj[cur])
            {
//                cout << next << " " << cap[cur][next] << " " << cap[next][cur] << "\n";
                if(next != s && !cap[cur][next])
                {
                    cout << rev_mp[next] << "\n";
                    break;
                }
            }
        }
    }
}
/*
2
4
4 Aa Ba Ca Da
3 Ab Bb Cb
2 Ac Bc
1 Ad
1
1 ApPlEs
*/

/*
4
3
2 Apples Oranges
1 Bananas
5 Apricots Blueberries Cranberries Zuccini Yams
1
1 ApPlEs
2
2 a b
1 axe
4
4 Aa Ba Ca Da
3 Ab Bb Cb
2 Ac Bc
1 Ad
*/

