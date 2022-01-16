#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int n, m, i, j, flag;
    pair<int, int> seg[102];

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> seg[i].ff >> seg[i].ss;

    vector<int> orphans;
    for(i = 1; i <= m; i++)
    {
        flag = 0;
        for(j = 0; j < n && !flag; j++)
        {
            if(seg[j].ff <= i && i <= seg[j].ss)
                flag = 1;
        }

        if(!flag)
            orphans.push_back(i);
    }

    cout << orphans.size() << "\n";
    for(auto o : orphans)
        cout << o << " ";
}
