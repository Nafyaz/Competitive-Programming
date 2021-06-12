#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, val, m, ans;

    char ch;
    string art;

    cin >> n;

    while(n--)
    {
        cin >> k;

        map<char, int> mp;
        ans = 0;

        while(k--)
        {
            cin >> ch >> val;
            mp[ch] = val;
        }

        cin >> m;
        getline(cin, art);

        while(m--)
        {
            getline(cin, art);

            for(auto u : art)
                ans += mp[u];
        }

        cout << fixed;
        cout << setprecision(2) << double(ans)/100 << "$\n";
    }
}
