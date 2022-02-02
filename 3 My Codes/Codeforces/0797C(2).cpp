//follow mohammedehab2002
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n;

    string mn(100005, 'z'+1);
    string s, t, u;

    cin >> s;

    n = s.size();

    for(i = n-1; i >= 0; i--)
        mn[i] = min(mn[i+1], s[i]);

    for(i = 0; i < n; i++)
    {
        t.push_back(s[i]);

        while(!t.empty() && t.back() <= mn[i+1])
        {
            u.push_back(t.back());
            t.pop_back();
        }
    }

    cout << u;
}
