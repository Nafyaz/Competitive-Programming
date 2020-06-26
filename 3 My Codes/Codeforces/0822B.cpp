#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j, k = 0;
    string s, t;

    set<int> minpos, pos;
    cin >> n >> m >> s >> t;

    int p, q;
    for(i = 0; i <= t.size() - s.size(); i++)
    {
        pos.clear();
        for(j = 0; j < s.size(); j++)
        {
            if(t[i+j] != s[j])
                pos.insert(j+1);
        }

        if(k == 0 || minpos.size() > pos.size())
        {
            minpos = pos;
            k = 1;
        }
    }

    cout << minpos.size() << endl;
    for(auto u : minpos)
        cout << u << " ";
}
