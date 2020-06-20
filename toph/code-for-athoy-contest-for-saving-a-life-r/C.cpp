#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, caseno = 0, n, i, j, a[100009];
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> v[1003];
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            v[a[i]].push_back(i);
        }

        int x, mx = 0, val, idx, pos;
        for(i = 0; i < n; i++)
        {
            val = a[i];
            idx = i;
            x = 1;
            while(1)
            {
                pos = upper_bound(v[val+1].begin(), v[val+1].end(), i) - v[val+1].begin();
//                cout << val << " " << idx << " " << pos << endl;
                if(pos == v[val+1].size())
                    break;
                val++;
                idx = v[val][pos];
                x++;
            }
            mx = max(mx, x);
        }

        cout << "Case #" << ++caseno << ": " << mx << endl;
    }
}
