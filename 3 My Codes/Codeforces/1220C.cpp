#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j;
    char mn;
    string s;
    cin >> s;
    mn = s[0];

    cout << "Mike" << endl;
    for(i = 1; i < s.size(); i++)
    {
        if(mn < s[i])
            cout << "Ann" << endl;
        else
            cout << "Mike" << endl;

        mn = min(mn, s[i]);
    }
}
