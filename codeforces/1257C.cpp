#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, a[200009], i, j, ans, freq[200009];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            freq[i] = 0;
        }

        i = j = 1;
        ans = INT_MAX;

        while(j <= n)
        {
            freq[a[j]]++;
            if(freq[a[j]] > 1)
            {
                while(freq[a[j]] > 1)
                {
                    freq[a[i]]--;
                    i++;
                }

                ans = min(ans, j - i + 2);
            }
            j++;
        }

        ans == INT_MAX? cout << -1 : cout << ans;
        cout << endl;
    }
}
