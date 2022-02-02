#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    return a+b < b+a;
}

int main()
{
    int n, i;
    string s[50004];

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> s[i];

    sort(s, s+n, cmp);

    cout << accumulate(s, s+n, string());
}
