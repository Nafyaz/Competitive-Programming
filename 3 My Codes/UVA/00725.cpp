#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int n, a, b, i, caseno = 0;

    string s = "0123456789", sa, sb;
    map<int, vector<pair<string, string>>> mp;

    do
    {
        a = b = 0;
        sa = sb = "";

        for(i = 0; i < 5; i++)
        {
            a *= 10;
            a += s[i] - '0';
            sa.push_back(s[i]);

            b *= 10;
            b += s[i+5] - '0';
            sb.push_back(s[i+5]);
        }

        if(a%b == 0)
            mp[a/b].push_back({sa, sb});

    }while(next_permutation(s.begin(), s.end()));

    while(cin >> n)
    {
        if(!n)
            break;
        if(caseno)
            cout << "\n";

        if(mp.find(n) == mp.end())
            cout << "There are no solutions for " << n << ".\n";
        else
        {
            for(auto u : mp[n])
                cout << u.ff << " / " << u.ss << " = " << n << "\n";
        }

        caseno++;
    }
}
