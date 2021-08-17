#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

bool cmp(pair<int, int> p, pair<int, int> q)
{
    return p.ss < q.ss;
}

int main()
{
    int t, n, i, i2, j, cnt, sup, ans;
    int rMat[50009][6];

    cin >> t;

    while(t--)
    {
        cin >> n;

        vector<pair<int, int>> r[6];
        vector<int> best;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= 5; j++)
            {
                cin >> rMat[i][j];
                r[j].push_back({i, rMat[i][j]});
            }
        }

        if(n == 1)
        {
            cout << 1 << "\n";
            continue;
        }

        for(j = 1; j <= 5; j++)
            sort(r[j].begin(), r[j].end(), cmp);

//        for(j = 1; j <= 5; j++)
//        {
//            for(auto u : r[j])
//                cout << u.ff << " " << u.ss << "; ";
//            cout << "\n";
//        }
//        cout << "\n\n";
//        for(i = 0; i < n; i++)
//        {
//            for(j = 1; j <= 5; j++)
//                cout << r[j][i].ff << " ";
//            cout << "\n";
//        }

        for(i = 1; i <= n; i++)
        {
            cnt = 0;
//            cout << "i: " << i << "; ";
            for(j = 1; j <= 5; j++)
            {
                pair<int, int> p = {i, rMat[i][j]};
                cnt += lower_bound(r[j].begin(), r[j].end(), p, cmp) - r[j].begin();
//                cout << "cnt: " << setw(3) << cnt << " ";
            }
//            cout << "\n";

            if(5*n - cnt - 5 >= 3*n - 3)
                best.push_back(i);
        }

        ans = -1;
        for(auto i : best)
        {
//            cout << "best: " << i << "\n";
            sup = 0;
            for(i2 = 1; i2 <= n; i2++)
            {
                if(i == i2)
                    continue;

                cnt = 0;
                for(j = 1; j <= 5; j++)
                {
                    if(rMat[i][j] < rMat[i2][j])
                        cnt++;
                }

                if(cnt >= 3)
                    sup++;
            }

            if(sup == n-1)
            {
                ans = i;
                break;
            }
        }

        cout << ans << "\n";
    }
}
