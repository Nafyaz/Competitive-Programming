#include<bits/stdc++.h>
using namespace std;

int vis[26], pr[26];
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
//    freopen("out.txt", "w", stdout);
    int i;
    string s, t;
    while(cin >> t)
    {
        for(i = 0; i < 26; i++)
        {
            vis[i] = 0;
            pr[i] = 0;
            adj[i].clear();
        }
        s = "";
        while(t != "#")
        {
            for(i = 0; i < t.size(); i++)
                pr[t[i] - 'A'] = 1;

            for(i = 0; i < t.size() && i < s.size(); i++)
            {
                if(t[i] != s[i])
                {
                    adj[s[i] - 'A'].push_back(t[i] - 'A');
                    break;
                }
            }
            s = t;

            cin >> t;
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
    }
}
/*
XWY
ZX
ZXY
ZXW
YWWX
#
*/
