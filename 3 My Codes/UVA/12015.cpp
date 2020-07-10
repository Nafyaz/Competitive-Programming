#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int t, caseno = 0, i, mx;
    vector<pair<string, int> > v(10);
    cin >> t;
    while(t--)
    {
        mx = 0;
        for(i = 0; i < 10; i++)
        {
            cin >> v[i].ff >> v[i].ss;
            mx = max(mx, v[i].ss);
        }

        cout << "Case #" << ++caseno << ":\n";
        for(i = 0; i < 10; i++)
        {
            if(v[i].ss == mx)
                cout << v[i].ff << endl;
        }
    }
}
