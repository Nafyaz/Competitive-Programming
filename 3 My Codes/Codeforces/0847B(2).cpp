//Follow ecnerwala
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

int main()
{
    int n, a, i, l, r, mid, pos;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;

        if(v.empty() || v.back().back() >= a)
        {
            v.push_back(vector<int>(1, a));
            continue;
        }

        l = 0;
        r = v.size();
        pos = -1;

        while(l <= r)
        {
            mid = (l+r)/2;

            if(v[mid].empty())
                r = mid-1;
            else if(v[mid].back() >= a)
                l = mid+1;
            else
            {
                pos = mid;
                r = mid - 1;
            }
        }

        v[pos].push_back(a);
    }

    for(auto u : v)
    {
        for(auto w : u)
            cout << w << " ";
        cout << "\n";
    }
}
