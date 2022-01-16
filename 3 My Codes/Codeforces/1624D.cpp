#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int freq[26];
    int t, n, k, i, ans, even, odd;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> n >> k >> s;

        memset(freq, 0, sizeof freq);
        for(i = 0; i < n; i++)
            freq[s[i]-'a']++;

        even = odd = 0;
        for(i = 0; i < 26; i++)
        {
            even += freq[i]/2;
            odd += freq[i]%2;
        }

        if(k > even)
        {
            cout << "1\n";
            continue;
        }

        ans = even/k*2;
        if(k <= n-ans*k)
            ans++;

        cout << ans << "\n";
    }
}
