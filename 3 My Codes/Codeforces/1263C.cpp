#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, i;

    cin >> t;

    while(t--)
    {
        cin >> n;

        set<int> s;

        s.insert(0);
        for(i = 1; i*i <= n; i++)
        {
            s.insert(i);
            s.insert(n/i);
        }

        cout << s.size() << "\n";
        for(auto u : s)
            cout << u << " ";
        cout << "\n";
    }
}
