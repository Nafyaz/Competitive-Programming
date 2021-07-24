#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, i, ans, mp;

    while(cin >> n)
    {
        if(!n)
            break;

        map<set<int>, int> freq;

        while(n--)
        {
            set<int> st;
            for(i = 0; i < 5; i++)
            {
                cin >> a;
                st.insert(a);
            }
            freq[st]++;
        }

        ans = mp = 0;
        for(auto u : freq)
            mp = max(mp, u.second);
        for(auto u : freq)
        {
            if(mp == u.second)
                ans += mp;
        }

        cout << ans << "\n";
    }
}
