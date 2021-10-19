#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, cnt[3] = {0}, fixed[300005] = {0}, temp;
    string s;

    cin >> n >> s;

    for(i = 0; i < n; i++)
    {
        cnt[s[i] - '0']++;
    }

    for(i = 0; i < n; i++)
    {
        if(cnt[0] < n/3 && cnt[s[i] - '0'] > n/3 && !fixed[i])
        {
            cnt[s[i] - '0']--;
            cnt[0]++;

            s[i] = '0';
        }
    }
    temp = 1;
    for(i = 0; i < n; i++)
    {
        if(s[i] == '0' && temp <= n/3)
        {
            fixed[i] = 1;
            temp++;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(cnt[1] < n/3 && cnt[s[i] - '0'] > n/3 && !fixed[i])
        {
            cnt[s[i] - '0']--;
            cnt[1]++;

            s[i] = '1';
            fixed[i] = 1;
        }
    }
    temp = 1;
    for(i = 0; i < n; i++)
    {
        if(s[i] == '1' && temp <= n/3)
        {
            fixed[i] = 1;
            temp++;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(cnt[2] < n/3 && cnt[s[i] - '0'] > n/3 && !fixed[i])
        {
            cnt[s[i] - '0']--;
            cnt[2]++;

            s[i] = '2';
            fixed[i] = 1;
        }
    }
    temp = 1;
    for(i = 0; i < n; i++)
    {
        if(s[i] == '2' && temp <= n/3)
        {
            fixed[i] = 1;
            temp++;
        }
    }

    cout << s;
}
