#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    string s, t;
    cin >> n;
    cin >> s >> t;
    vector <pair <char, int> > vs, vt;

    for(i = 0; i < n; i++)
    {
        if(s[i] != t[i])
        {
            vs.push_back({s[i], i});
            vt.push_back({t[i], i});
        }
    }

    sort(vs.begin(), vs.end());
    sort(vt.begin(), vt.end());

    int len = vs.size(), p1 = 0, p2 = 0, found = 0, pos1, pos2;
    while(p1 < len && p2 < len)
    {
        if(vs[p1].first < vt[p2].first)
            p1++;
        else if(vs[p1].first > vt[p2].first)
            p2++;
        else if(vs[p1].first == vt[p2].first)
        {
            found = 1;
            pos1 = vs[p1].second;
            pos2 = vt[p2].second;

            if(s[pos2] == t[pos1])
            {
                cout << len - 2 << endl;
                cout << pos1 + 1 << " " << pos2 + 1;
                return 0;
            }

            p1++;
            p2++;
        }
    }

    if(found)
    {
        cout << len - 1 << endl;
        cout << pos1 + 1 << " " << pos2 + 1;
    }

    else
    {
        cout << len << endl;
        cout << "-1 -1";
    }
}
