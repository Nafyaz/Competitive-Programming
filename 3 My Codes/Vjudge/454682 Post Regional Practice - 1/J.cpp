#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

bool cmp(pair<int, int> p, pair<int, int> q)
{
    if(p.ss != q.ss)
        return p.ss > q.ss;
    return p.ff < q.ff;
}

int main()
{
    int t, n, k, i, a[100005], ans[100005], flag;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        map<int, int> freq;

        for(i = 0; i < n; i++)
        {
            cin >> a[i];

            freq[a[i]]++;
        }

        vector<pair<int, int>> v;

        for(auto u : freq)
        {
            v.push_back(u);
        }

        sort(v.begin(), v.end(), cmp);

        queue<pair<int, int>> q;

        for(auto u : v)
            q.push(u);

        for(i = 0; i < n; i++)
        {
            pair<int, int> x = q.front();
            q.pop();

            ans[i] = x.ff;
            if(x.ss > 1)
                q.push({x.ff, x.ss-1});
        }

        flag = 1;
        for(i = 0; i+k < n; i++)
        {
            if(ans[i] != ans[i+k])
            {
                flag = 0;
                break;
            }
        }

        if(!flag)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for(i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
