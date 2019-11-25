#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, i, u, j;
    cin >> n >> k;

    vector <int> a[200010];
//    set <int> st;

    for(i = 0; i < n; i++)
    {
        cin >> u;
        j = 0;
        while(u)
        {
            a[u].push_back(j);
//            st.insert(u);
            u = u >> 1;
            j++;
        }
//        sort(a[i].begin(), a[i].end());
    }

    int ans = INT_MAX;
    for(i = 1; i < 200010; i++)
    {
        if(a[i].size() < k)
            continue;
        sort(a[i].begin(), a[i].end());
        ans = min(ans, accumulate(a[i].begin(), a[i].begin() + k, 0));
    }

    cout << ans;
}
