#include<bits/stdc++.h>
using namespace std;

int n, cnt[3];
string s;

void frwd(int x)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(cnt[x] < n/3 && cnt[s[i]-'0'] > n/3 && s[i]-'0' > x)
        {
            cnt[x]++;
            cnt[s[i]-'0']--;

            s[i] = '0'+x;
        }
    }
}
void bkwd(int x)
{
    int i;
    for(i = n-1; i >= 0; i--)
    {
        if(cnt[x] < n/3 && cnt[s[i]-'0'] > n/3 && s[i]-'0' < x)
        {
            cnt[x]++;
            cnt[s[i]-'0']--;

            s[i] = '0' + x;
        }
    }
}

int main()
{
    int i;
    cin >> n >> s;

    for(i = 0; i < n; i++)
        cnt[s[i] - '0']++;

    frwd(0);
    frwd(1);
    bkwd(2);
    bkwd(1);

    cout << s;
}
