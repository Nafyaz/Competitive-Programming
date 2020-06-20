#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, caseno = 0, n, i, j, a[100009], ans[100009], mx;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> v[1003];
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            v[a[i]].push_back(i);
            ans[i] = 1;
        }

        mx = 1;

        for(i = 1; i < 1003; i++)
        {
            if(!v[i-1].empty() && !v[i].empty() && v[i].back() > v[i-1][0])
            {
                ans[i] = ans[i-1] + 1;
                mx = max(mx, ans[i]);
            }
        }

        cout << "Case #" << ++caseno << ": " << mx << endl;
    }
}
