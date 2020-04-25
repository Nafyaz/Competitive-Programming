#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("out.txt", "w", stdout);
    int t, n, i, j;
    string s;
    char c;
    cin >> t;
    while(t--)
    {
        cin >> s;
        if(s.back() == 'B' || s[0] == 'W')
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        vector<int> b, w;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == 'B')
                b.push_back(i);
            else
                w.push_back(i);
        }

        if(b.back() < w[0])
        {
            cout << 1 << endl;
            cout << s.size() << " ";
            for(i = 1; i <= s.size(); i++)
                cout << i << " ";
            cout << endl;
            continue;
        }

        cout << 2 << endl;

        cout << w.size() << " " << b[0] + 1 << " ";
        for(i = 0; i < w.size()-1; i++)
            cout << w[i] + 1 << " ";
        cout << endl;

        cout << b.size() << " ";
        for(i = 1; i < b.size(); i++)
            cout << b[i] + 1 << " ";
        cout << w.back() << " ";
        cout << endl;
    }
}
