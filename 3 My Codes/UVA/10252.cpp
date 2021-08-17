#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int i;
    string a, b, ans;

    while(getline(cin, a))
    {
        getline(cin, b);

        map<char, int> fa, fb;
        ans = "";

        for(auto u : a)
            fa[u]++;

        for(auto u : b)
            fb[u]++;

        for(auto u : fa)
        {
            for(i = 1; i <= u.ss && i <= fb[u.ff]; i++)
                ans.push_back(u.ff);
        }

        cout << ans << "\n";
    }
}
