#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int m, n, k, t;
vector<pair<int, int> > a, trap[200009];

bool check(int mid)
{
    int i, t0 = 0, spos = 0, mypos = 0, sa = a[mid].ff;
    i = 1;
    while(spos <= n)
    {
        if(trap[spos+1].size() > 0)
        {
            for(j = 0; j < trap[spos+1].size(); j++)
            {
                while(i <= mypos)
                {
    //                cout << i << endl;
                    i++;
                    if(trap[i].ss > sa)
                        mypos = max(mypos, trap[i].ss);
                }
            }

        }

        if(mypos > spos)
        {
            t0 += 3*(mypos - spos);
            spos = mypos;
        }
        else
        {
            t0++;
            mypos++;
            spos++;
            i++;
        }
    }

    return t0 <= t;
}

int main()
{
    int i, x, cumulative[200009] = {0};
    cin >> m >> n >> k >> t;

    map<int, int> mp;

    for(i = 0; i < m; i++)
    {
        cin >> x;
        mp[x]++;
    }

    for(auto u : mp)
    {
        a.push_back({u.ff, u.ss});
//        cout << "lol";
//        cout << u.ff << " " << u.ss << endl;
    }


    for(i = a.size()-1; i >= 0; i--)
        cumulative[i] += cumulative[i+1] + a[i].ss;

//    cout << "lol";
//    for(i = 0; i <= a.size(); i++)
//        cout << cumulative[i] << endl;
//    cout << "lol";

    int y, z;
    for(i = 0; i < k; i++)
    {
        cin >> x >> y >> z;
        trap[x].push_back({y, z});
    }

    cout << check(0);

//    int ans = 0, low = 0, high = a.size(), mid;
//    while(low <= high)
//    {
//

//        mid = (low + high)/2;
//        if(check(mid))
//        {
//            ans = cumulative[mid];
//            high = mid-1;
//        }
//        else
//            low = mid+1;
//    }

//    cout << ans;
}
