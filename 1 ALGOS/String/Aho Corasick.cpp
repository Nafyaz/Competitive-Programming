#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 200005;

map <string, int> id;
string query[N], s, comp[N];
int n, m, ptr, last[N], ans[N];
int ending[N];
int counter[N],starting[N];
struct AC
{
    int N, P;
    vector<vector<int>> next;
    vector<int> link, out_link;
    vector<vector<int>> out;
    AC(): N(0), P(0)
    {
        node();
    }
    int node()
    {
        next.emplace_back(26, 0);
        link.emplace_back(0);
        out_link.emplace_back(0);
        out.emplace_back(0);
        return N++;
    }
    int add_pattern(const string T)
    {
        int u = 0;
        for (auto c : T)
        {
            if (!next[u][c - 'a']) next[u][c - 'a'] = node();
            u = next[u][c - 'a'];
        }
        out[u].push_back(P);
        return P++;
    }
    void compute()
    {
        queue<int> q;
        for (q.push(0); !q.empty(); )
        {
            int u = q.front();
            q.pop();
            // automaton:
            for (int c = 0; c < 26; ++c)
            {
                int v = next[u][c];
                if (!v) next[u][c] = next[link[u]][c];
                else
                {
                    link[v] = u ? next[link[u]][c] : 0;
                    out_link[v] = out[link[v]].empty() ? out_link[link[v]] : link[v];
                    q.push(v);
                }
            }
        }
    }
    int advance(int u, char c)
    {

        while (u && !next[u][c - 'a']) u = link[u];
        u = next[u][c - 'a'];
        return u;
    }
    void match(const string S)
    {
        int u = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            char c = S[i];
            u = advance(u, c);

            for (int v = u; v; v = out_link[v])
            {
                for (auto p : out[v])
                {
                    ++ans[p];
                    ending[i] += counter[p];
                    starting[i - comp[p].size() + 1] += counter[p];
                    last[p] = i;
                }
            }
        }
    }
} aho;

int main()
{
    cin >> s;
    n = s.size();
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> query[i];
        if (id.find(query[i]) == id.end())
        {
            comp[ptr] = query[i];
            id[query[i]] = ptr++;
            aho.add_pattern(query[i]);
        }
        counter[id[query[i]]]++;
    }

    aho.compute();
    memset(last, -1, sizeof last);
    aho.match(s);
    ll answer = 0;
//  for(int i = 0;i < n;i++){
//    cout << starting[i] << " ";
//  }
//  cout << endl;
    for(int i = 0; i < n - 1; i++)
    {
        ll cnt = (ll)ending[i] * (ll)starting[i + 1];
        answer += cnt;
    }
    cout << answer << "\n";
    return 0;
}
