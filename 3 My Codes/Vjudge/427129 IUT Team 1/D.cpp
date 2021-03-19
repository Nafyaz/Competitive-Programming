#include<bits/stdc++.h>
using namespace std;

vector<int> idx[5009];
map<int, int> mp;
int cxor[5009];

int main()
{
    int t, n, i, j, a, ans;

    cin >> t;

    while(t--)
    {
        mp.clear();

        cin >> n;

        ans = n;

        for(i = 0, j = 1; i < n; i++)
        {
            cin >> a;
            if(mp.find(a) == mp.end())
            {
                mp[a] = j;
                j++;
            }

            idx[mp[a]].push_back(j);
            cxor[i+1] = cxor[i] ^ a;
        }

        for(i = 1; i <= n; i++)
        {
            for(j = i-2; j >= 1; j -= 2)
            {
                int range_xor = cxor[i] ^ cxor[j-1];
                a = mp[range_xor];
                int cnt = lower_bound(idx[a].begin(), idx[a].end(), i+1) - lower_bound(idx[a].begin(), idx[a].end(), j);
                if(cnt%2 == 1)

            }
        }
    }
}
