#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i;
    vector <int> v[26];

    cin >> s;

    for(i = 0; i < s.size(); i++)
        v[s[i] - 'a'].push_back(i);

    int pos = -1, j;
    for(i = 25; i >= 0; i--)
    {
        if(!v[i].empty())
        {
            for(j = 0; j < v[i].size(); j++)
            {
                if(v[i][j] > pos)
                {
                    cout << char('a' + i);
                    pos = v[i][j];
                }
            }
        }
    }
}
