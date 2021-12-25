#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, n, k, val, ans;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        multiset<int> ms;

        while(n)
        {
            ms.insert(n%10);
            n /= 10;
        }

        while(k--)
        {
            val = *ms.begin();
            if(val == 9)
                break;

            ms.erase(ms.begin());
            ms.insert(val+1);
        }

        ans = 1;
        for(auto u : ms)
            ans *= u;

        cout << ans << "\n";
    }
}
