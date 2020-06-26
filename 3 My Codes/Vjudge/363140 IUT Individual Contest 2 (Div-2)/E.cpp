#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, flag = 0;
    string s;
    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] != '/')
            flag = 1;
    }
    if(!flag)
    {
        cout << '/';
        return 0;
    }

    for(j = s.size() - 1; j >= 0 && s[j] == '/'; j--);

    for(i = 0; i < s.size() && i <= j; i++)
    {
        if(s[i] != '/')
        {
            cout << s[i];
            continue;
        }

        while(i+1 < s.size() && s[i+1] == '/')
            i++;

        cout << '/';
    }
}
