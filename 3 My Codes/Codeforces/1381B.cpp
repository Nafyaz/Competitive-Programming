#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int t, i, n, last, p[4009];
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<pair<int, int>> pos;

        for(i = 0; i < 2*n; i++)
        {
            cin >> p[i];
            pos.push_back({p[i], i});
        }

        sort(pos.begin(), pos.end());

        vector<int> v, took(2*n);
        last = 2*n;
        for(i = 2*n - 1; i >= 0; i--)
        {
            if(pos[i].ff == last)
            {

            }
        }
    }
}
