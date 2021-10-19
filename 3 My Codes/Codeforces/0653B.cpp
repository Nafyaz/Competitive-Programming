#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, i;

    cin >> n >> q;

    string a, b, s;
    queue<string> my_q;
    vector<string> adj[26];

    for(i = 0; i < q; i++)
    {
        cin >> a >> b;
        adj[b[0] - 'a'].push_back(a);
    }

    my_q.push("a");
    while(!my_q.empty())
    {
        s = my_q.front();
        if(s.size() == n)
            break;

        my_q.pop();

        for(auto u : adj[s[0]-'a'])
            my_q.push(u + s.substr(1));
    }

    set<string> my_s;
    while(!my_q.empty())
    {
        my_s.insert(my_q.front());
        my_q.pop();
    }

    cout << my_s.size();
}
