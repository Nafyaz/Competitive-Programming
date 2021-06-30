#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int t, total;
    string s;

    cin >> t;

    getline(cin, s);
    getline(cin, s);

    while(t--)
    {
        map<string, int> mp;
        total = 0;

        while(getline(cin, s))
        {
            if(s == "")
                break;

            mp[s]++;
            total++;
        }

        cout << fixed;
        for(auto u : mp)
            cout << u.ff << " " << setprecision(4) << (double)u.ss*100/total << "\n";

        if(t)
            cout << "\n";
    }
}
