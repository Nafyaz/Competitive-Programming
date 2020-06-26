#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int t, n, i, j, csum[8009], ans;
    vector<pair<int, int> > v(8009);
    csum[0] = 0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> v[i].ff;
            v[i].ss = i;
            csum[i] = csum[i-1] + v[i].ff;
        }

        sort(v.begin()+1, v.begin()+n+1);

//        for(i = 1; i <= n; i++)
//            cout << v[i].ff << " " << v[i].ss << endl;

        ans = 0;
        for(i = 3; i <= n; i++)
        {
            for(j = 1; j < i; j++)
            {
                int pos = lower_bound(csum + v[j].ss, csum + n+1, v[i].ff + csum[v[j].ss-1]) - csum;
//                cout << i << " " << j << " " << pos << " " << csum[pos] - csum[v[j].ss-1] << endl;
                if(pos - v[j].ss + 1 >= 2 && csum[pos] - csum[v[j].ss-1] == v[i].ff)
                {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}
