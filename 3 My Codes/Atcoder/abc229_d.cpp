#include<bits/stdc++.h>
using namespace std;

vector<int> dotIdx;

int main()
{
    string s;
    int i, k, ans = 0;

    cin >> s >> k;

    s = '#' + s + '#';

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] != 'X')
            dotIdx.push_back(i);
    }

    for(i = 1; i < dotIdx.size(); i++)
        ans = max(ans, dotIdx[min(i+k, (int)dotIdx.size()-1)] - dotIdx[i-1] - 1);

    cout << ans;
}
