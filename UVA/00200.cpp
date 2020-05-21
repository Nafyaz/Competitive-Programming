#include<bits/stdc++.h>
using namespace std;

int n, vis[26], pr[26];
string s[10009], t[10009];
stack<int> st;
vector<int> adj[26];

void dfs(int s)
{
    vis[s] = 1;
    for(auto u : adj[s])
    {
        if(vis[u] == 0)
            dfs(u);
    }
    st.push(s);
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i, j, cnt = 0;
    string x;

    while(1)
    {
//        for(i = 0; i < n; i++)
//            cout << s[i] << " ";
//        cout << endl;
        cin >> x;
        if(x == "#")
        {
            for(i = 0; i < 20; i++)
            {
                for(j = 1; j < n; j++)
                {
                    if(i < s[j].size())
                        pr[s[j][i] - 'A'] = 1;
                    if(i < s[j-1].size())
                        pr[s[j-1][i] - 'A'] = 1;

                    if(i >= s[j].size() || i >= s[j-1].size())
                        continue;
                    if(t[j] == t[j-1] && s[j-1][i] != s[j][i])
                        adj[s[j-1][i] - 'A'].push_back(s[j][i] - 'A');

                    t[j-1] = t[j-1] + s[j-1][i];
                }
                if(i < s[j-1].size())
                {
                    t[j-1] = t[j-1] + s[j-1][i];
                    pr[s[j-1][i] - 'A'] = 1;
                }
            }

            for(i = 0; i < 26; i++)
            {
                if(pr[i] && !vis[i])
                    dfs(i);
            }

            while(!st.empty())
            {
                cout << (char)(st.top() + 'A');
                st.pop();
            }
            cout << endl;

            //clearing
            for(i = 0; i < 26; i++)
            {
                vis[i] = 0;
                adj[i].clear();
                pr[i] = 0;
            }
            for(i = 0; i < n; i++)
                t[i].clear();
            cnt = 0;
        }
        else
        {
            s[cnt++] = x;
            n = cnt;
        }
    }
}
/*
P
F
FNP
FNF
FNFNF
FNFNN
#
*/
