#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, cur_pos;
    string s, ans, temp;
    list<char> l;
    list<char>::iterator it;

    while(cin >> s)
    {
        l.clear();

        s = '[' + s + ']';

        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == '[')
            {
                it = l.begin();
                continue;
            }
            else if(s[i] == ']')
            {
                it = l.end();
                continue;
            }

            l.insert(it, s[i]);
        }

        for(auto u : l)
            cout << u;
        cout << "\n";
    }
}
