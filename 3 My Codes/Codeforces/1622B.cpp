#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int p[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, i, val;
    string s;
    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> p[i];
        cin >> s;

        vector<pair<int, int>> zero, one;
        for(i = 0; i < n; i++)
        {
            if(s[i] == '0')
                zero.push_back({p[i], i});
            else
                one.push_back({p[i], i});
        }

        sort(zero.begin(), zero.end());
        sort(one.begin(), one.end());

        for(i = 0, val = 1; i < zero.size(); i++, val++)
            p[zero[i].ss] = val;
        for(i = 0; i < one.size(); i++, val++)
            p[one[i].ss] = val;

        for(i = 0; i < n; i++)
            cout << p[i] << " ";
        cout << "\n";
    }
}
