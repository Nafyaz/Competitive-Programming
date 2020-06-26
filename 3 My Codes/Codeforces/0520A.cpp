#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int i, freq[26] = {0};
    for(i = 0; i < n; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            freq[s[i] - 'a']++;
        else
            freq[s[i] - 'A']++;
    }

    for(i = 0; i < 26; i++)
    {
        if(!freq[i])
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
