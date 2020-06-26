#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j, x;
    cin >> n >> m;

    vector<int> v[n+1];
    string s;

    while(m--)
    {
        cin >> x >> s;
        if(v[x].empty() || v[x].back() == 0)
            v[x].push_back(s == "AC");
    }

    int point = 0, penalty = 0;
    for(auto u : v)
    {
        if(u.empty() || u.back() == 0)
            continue;
        else
        {
            point++;
            penalty += u.size() -1;
        }
    }

    cout << point << " " << penalty;
}

