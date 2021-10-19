#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, flag = 0;
    string s;

    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        if(flag == 0 && s[i] == 'a')
            continue;
        if(flag == 1 && s[i] == 'a')
            break;

        s[i] = s[i] - 1;
        flag = 1;
    }

    cout << s;
}
