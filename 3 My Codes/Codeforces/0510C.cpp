#include<bits/stdc++.h>
using namespace std;

vector<int> adj[26];
int in[26];
vector<int> path;

void topsort()
{
    int i;
    queue<int> Q;
    for(i = 0; i < 26; i++)
    {
        if(in[i] == 0)
        {
            Q.push(i);
        }
    }

    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        path.push_back(node);
        for(auto u : adj[node])
        {
            in[u]--;
            if(in[u] == 0)
                Q.push(u);
        }
    }
}

int main()
{
    string s, t;
    int i, j, n;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> t;
        for(j = 0; j < t.size() && j < s.size(); j++)
        {
            if(t[j] != s[j])
            {
                adj[s[j] - 'a'].push_back(t[j] - 'a');
                in[t[j] - 'a']++;
                break;
            }
            if(j == t.size()-1 && j < s.size()-1)
            {
                cout << "Impossible";
                return 0;
            }
        }
        s = t;
    }

//    for(i = 0; i < 26; i++)
//        cout << in[i] << " ";

    topsort();

    if(path.size() < 26)
    {
        cout << "Impossible";
        return 0;
    }

    for(auto u : path)
        cout << (char)(u + 'a');
}
