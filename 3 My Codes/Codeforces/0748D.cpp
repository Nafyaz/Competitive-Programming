#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

bool isPalindrome(string s)
{
    string t = s;
    reverse(t.begin(), t.end());

    return s == t;
}

int main()
{
    ll k, n, a, ans, x, y;
    string s;

    map<string, ll> freq, palFreq;
    map<string, priority_queue<ll>> value;

    cin >> k >> n;

    while(k--)
    {
        cin >> s >> a;

        if(isPalindrome(s))
            palFreq[s]++;
        else
            freq[s]++;
        value[s].push(a);
    }

    ans = 0;
    for(auto u : freq)
    {
        s = u.ff;
        reverse(s.begin(), s.end());

        while(!value[u.ff].empty() && !value[s].empty())
        {
            x = value[u.ff].top();
            value[u.ff].pop();
            freq[u.ff]--;

            y = value[s].top();
            value[s].pop();
            freq[s]--;

            if(x+y > 0)
                ans += x+y;
            else
            {
                value[u.ff].push(x);
                freq[u.ff]++;

                value[s].push(y);
                freq[s]++;

                break;
            }
        }
    }

    ll mny = INT_MAX;
    for(auto u : palFreq)
    {
        while(value[u.ff].size() >= 2)
        {
            x = value[u.ff].top();
            if(x <= 0)
                break;
            value[u.ff].pop();
            palFreq[u.ff]--;

            y = value[u.ff].top();

            value[u.ff].pop();
            palFreq[u.ff]--;

            if(x+y > 0)
            {
                ans += x+y;
                mny = min(mny, y);
            }
            else
            {
                value[u.ff].push(x);
                palFreq[u.ff]++;

                value[u.ff].push(y);
                palFreq[u.ff]++;

                break;
            }
        }
    }

    ll mx = INT_MIN;
    for(auto u : palFreq)
    {
        if(!value[u.ff].empty())
            mx = max(mx, value[u.ff].top());
    }

    ll mxans = ans;
    mxans = max(mxans, ans + mx);
    mxans = max(mxans, ans - mny);

    cout << mxans;
}
