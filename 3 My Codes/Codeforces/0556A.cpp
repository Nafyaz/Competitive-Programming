#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, z = 0, o = 0;
    string s;

    cin >> n >> s;
    for(i = 0; i < n; i++)
    {
        if(s[i] == '1')
            o++;
        else
            z++;
    }

    cout << abs(o - z);
}
