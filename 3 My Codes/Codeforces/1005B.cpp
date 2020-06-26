#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;

    int i = s.size() - 1, j = t.size() - 1;

    while(i >= 0 && j >= 0)
    {
        if(s[i] != t[j])
            break;
        i--;
        j--;
    }

    cout << i + j + 2;
}
