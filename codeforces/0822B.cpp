#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j, k = -1;
    string s, t;

    set<int> minpos, pos;
    cin >> n >> m >> s >> t;

    vector <int> v[26];

    for(i = 0; i < s.size(); i++)
    {
        v[s[i] - 'a'].push_back(i);
    }

    int p, q;
    for(i = 0; i < t.size(); i++)
    {
        for(auto u : v[t[i] - 'a'])
        {
            if(i < u || t.size() - i < s.size() - u)
                continue;

            pos.clear();
            p = i - u;
            q = 0;
            while(q < s.size())
            {
                if(t[p] != s[q])
                    pos.insert(q+1);
                p++;
                q++;
            }

            if(k == -1 || minpos.size() > pos.size())
            {
                k = 1;
                minpos = pos;
            }
        }
    }

    cout << minpos.size() << endl;
    for(auto u : minpos)
        cout << u << " ";
}
