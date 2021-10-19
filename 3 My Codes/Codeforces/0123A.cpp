#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
bool flag[1003];

void sieve()
{
    int i, j;

    flag[2] = 1;
    for(i = 3; i < 1003; i += 2)
        flag[i] = 1;

    for(i = 3; i < 1003; i += 2)
    {
        if(flag[i])
        {
            for(j = i*i; j < 1003; j += 2*i)
                flag[j] = 0;
        }
    }

    primes.push_back(2);
    for(i = 3; i < 1003; i += 2)
    {
        if(flag[i])
            primes.push_back(i);
    }
}

int main()
{
    sieve();

    int i, j, n, cnt = 1, mx = 0;
    char mxch;
    string s;
    map<char, int> freq;

    cin >> s;

    n = s.size();

    for(i = 0; i < primes.size() && primes[i] <= n; i++)
    {
        if(primes[i]*2 > n)
            cnt++;
    }

    for(auto u : s)
    {
        freq[u]++;
        if(mx < freq[u])
        {
            mx = freq[u];
            mxch = u;
        }
    }

    if(mx < n-cnt)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    string ans(n, mxch);

    for(i = j = 0; i < n && j < n; i++)
    {
        while(j < n && s[j] == mxch)
            j++;
        if(!flag[i+1] && i || flag[i+1] && 2*(i+1) <= n)
            continue;
        else if(j < n)
        {
            ans[i] = s[j];
            j++;
        }

    }

    cout << ans;
}
