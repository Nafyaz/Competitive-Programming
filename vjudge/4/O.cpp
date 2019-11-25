#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    int i, len = s.size();
    map <char, char> a, b;
    map<char,char>::iterator ita, itb;
    for(i = 0; i < len; i++)
    {
        ita = a.find(s[i]), itb = b.find(t[i]);

        if(ita == a.end() && itb == b.end())
        {
            a.insert({s[i], t[i]});
            b.insert({t[i], s[i]});
        }
        else if(ita == a.end() || itb == b.end())
        {
            printf("No");
            return 0;
        }
        else if(a[s[i]] != t[i] || b[t[i]] != s[i])
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
}
