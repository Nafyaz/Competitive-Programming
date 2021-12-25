#include<bits/stdc++.h>
using namespace std;


int findDiff(string a, string b)
{
    int freqa[26] = {0};
    int freqb[26] = {0};

    for(auto u : a)
        freqa[u - 'A']++;
    for(auto u : b)
        freqb[u - 'A']++;

    int ret = 0;
    for(int i = 0; i < 26; i++)
    {
        if(freqa[i] != freqb[i])
            ret++;
    }

    return ret;
}

int main()
{
    int T, n, i, j, diff, mndiff;
    string s[102];
    pair<string, string> ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> s[i];

        sort(s, s+n);

        mndiff = INT_MAX;
        for(i = 0; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                diff = findDiff(s[i], s[j]);
                if(diff < mndiff)
                {
                    mndiff = diff;
                    ans.first = s[i];
                    ans.second = s[j];
                }
            }
        }

        cout << ans.first << " " << ans.second << "\n";
    }
}
