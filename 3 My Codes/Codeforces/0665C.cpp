#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    cin >> s;

    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i-1])
        {
            s[i]++;
            if(s[i] > 'z')
                s[i] = s[i] - 'z' + 'a' - 1;
            if(i+1 < s.size() && s[i] == s[i+1])
                s[i]++;
            if(s[i] > 'z')
                s[i] = s[i] - 'z' + 'a' - 1;
        }
    }

    cout << s;
}
