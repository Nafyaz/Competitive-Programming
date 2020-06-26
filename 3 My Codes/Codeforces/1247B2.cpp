#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int main()
{
    int t, n, k, d, i, j;

    map <int, int> cnt;

    cin >> t;

    while(t--)
    {
        cnt.clear();
        cin >> n >> k >> d;
        int a[n];

        for(i = 0; i < n; i++)
            cin >> a[i];

        int sz, ans = INT_MAX;
        set <int> s;

        i = j = 0;

        while(j < n)
        {

            if(j-i + 1 < d)
            {
                cout << i << " " << j << endl;
                cnt[a[j]]++;
                s.insert(a[j]);
                j++;

                if(j-i == d)
                {
                    sz = s.size();
                    ans = min(ans, sz);
                }
            }

            else
            {
                cnt[a[i]]--;
                if(cnt[a[i]] == 0)
                    s.erase(s.find(cnt[a[i]]));

                i++;
                j++;
                cnt[a[j]]++;

                s.insert(a[j]);

                sz = s.size();
                ans = min(ans, sz);
            }
        }

        cout << ans << endl;
    }
}
