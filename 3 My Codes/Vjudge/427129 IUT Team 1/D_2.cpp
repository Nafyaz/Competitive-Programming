#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int a[5009];
bool freq[5009];
unordered_map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("cases.in", "r", stdin);
    int t, n, i, j, ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        mp.clear();

        for(i = 0, j = 0; i < n; i++)
        {
            cin >> a[i];
            if(mp.find(a[i]) == mp.end())
            {
                mp[a[i]] = j;
                j++;
            }
        }

        ans = 0;
        for(i = 0; i < n; i++)
        {
            memset(freq, 0, sizeof freq);
            int odds = 0;

            ans++;
            freq[mp[a[i]]] ^= 1;
            odds++;

//            cout << i << " " << i << ":\n";
//            for(int k = 1; k <= 9; k++)
//                cout << k << ": " << freq[k] << "\n";

            for(j = i+2; j < n; j += 2)
            {
                freq[mp[a[j-1]]] ^= 1;
                freq[mp[a[j]]] ^= 1;

                if(a[j] != a[j-1])
                {
                    odds += (freq[mp[a[j-1]]]? 1 : -1);
                    odds += (freq[mp[a[j]]]? 1 : -1);
                }

                if(odds == 1)
                    ans++;

//                cout << i << " " << j << ":\n";
//                for(int k = 1; k <= 9; k++)
//                    cout << k << ": " << freq[k] << "\n";
            }
        }

        cout << ans << "\n";
    }
}
