//Credit goes to https://codeforces.com/blog/entry/68534?#comment-528842
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long w = 0, wo = 0, wow = 0, i;
    string s;
    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        if(i > 0 && s[i-1] == 'v' && s[i] == 'v')
            w++;
        if(s[i] == 'o')
            wo += w;
        if(i > 0 && s[i-1] == 'v' && s[i] == 'v')
            wow += wo;
    }

    cout << wow;
}
