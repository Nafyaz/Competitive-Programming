#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

string s;
int daysInMonth[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isCorrect(int i)
{
    if(s[i+2] != '-' || s[i+5] != '-')
        return 0;

    if(s[i] == '-' || s[i+1] == '-')
        return 0;
    int d = (s[i] - '0')*10 + s[i+1] - '0';

    if(s[i+3] == '-' || s[i+4] == '-')
        return 0;
    int m = (s[i+3] - '0')*10 + s[i+4] - '0';

    if(s[i+6] == '-' || s[i+7] == '-' || s[i+8] == '-' || s[i+9] == '-')
        return 0;
    int y = (s[i+6] - '0')*1000 + (s[i+7] - '0')*100 + (s[i+8] - '0')*10 + (s[i+9] - '0');

    if(m <= 0 || m > 12 || d <= 0 || d > daysInMonth[m] || y < 2013 || y > 2015)
        return 0;

    return 1;
}

int main()
{
    int i, mx = -1;
    map<string, int> freq;
    string ans;

    cin >> s;

    for(i = 0; i+10 <= s.size(); i++)
    {
        if(isCorrect(i))
            freq[s.substr(i, 10)]++;
    }

    for(auto u : freq)
    {
        if(u.ss > mx)
        {
            ans = u.ff;
            mx = u.ss;
        }
    }

    cout << ans;
}
