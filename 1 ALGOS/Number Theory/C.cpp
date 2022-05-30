#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "

string s[102];
vector<ll> adj[26];
ll col[26];
stack<ll> stk;

void call(ll pos, ll bg, ll ed)
{
    // if(pos == 3)
    //     cout << bg << " " << ed << "\n";

    ll i;

    for(i = bg+1; i <= ed; i++)
    {
        if(pos < s[i-1].size() && pos < s[i].size() && s[i-1][pos] != s[i][pos])
        {
            adj[s[i-1][pos] - 'a'].push_back(s[i][pos] - 'a');
            call(pos+1, bg, i-1);
            bg = i;
        }
     
        // if(pos == 3)
        // {   
        //     show(i);
        //     show(bg);
        //     show(ed);
        //     cout << "\n";
        // }
    }

    if(pos < s[bg].size())
        call(pos+1, bg, ed);
}

bool dfs(int s)
{
    int ret = 1;
    col[s] = 1;
    for(auto u : adj[s])
    {
        if(col[u] == 0)
            ret = ret & dfs(u);
        else if(col[u] == 1)
            return 0;
    }
    col[s] = 2;
    stk.push(s);
    return ret;
}

void solve()
{
    ll i, j, n;
    set<char> st;

    cin >> n;

    for(i = 0; i < n; i++)    
    {
        cin >> s[i];
        for(j = 0; j < s[i].size(); j++)        
            st.insert(s[i][j]);      

        col[i] = 0;
        adj[i].clear();  
    }

    // cout << "st:\n";
    // for(auto u : st)
    //     cout << u << ' ';
    // cout << "\n";
    
    call(0, 0, n-1);

    // for(auto u : adj['l' - 'a'])
    //     cout << (char)(u + 'a') << "\n";

    for(i = 0; i < 26; i++)
    {
        if(st.find(i+'a') != st.end() && col[i] == 0)
            dfs(i);
    }

    // cout << "stk:\n";
    while(!stk.empty())
    {
        cout << (char)(stk.top() + 'a') << " ";
        st.erase((ll)(stk.top()+'a'));
        stk.pop();

        // cout << "st:\n";
        // for(auto u : st)
        //     cout << u << ' ';
        // cout << "\n";
    }

    // cout << "\nin set:\n";
    for(auto u : st)
        cout << u << " ";    
    cout << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}