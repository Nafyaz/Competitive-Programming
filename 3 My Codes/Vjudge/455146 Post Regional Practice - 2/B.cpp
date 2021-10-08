#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, caseno = 0, n, m, i;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        unordered_map<string, bool> mp;

        while(n--)
        {
            cin >> s;

            if(s.size() >= 2)
                sort(s.begin()+1, s.end()-1);

            mp[s] = 1;
        }

        cout << "Case #" << ++caseno << ": ";

        while(m--)
        {
            cin >> s;

            if(s.size() >= 2)
                sort(s.begin()+1, s.end()-1);

            if(mp.find(s) != mp.end())
                cout << 1;
            else
                cout << 0;
        }
        cout << "\n";
    }
}
