#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int func(int k)
{
    int cnt, flag, i, ret = 0;

    for(int l = k; l > 0; l--)
    {
//        int l = 3;
        vector<int> v2(l);
        flag = 1;
        cnt = 0;
        while(flag)
        {
            for(i = 0; i < k; i++)
            {
                v2[i%l]++;
                if(v2[i%l] > v[i%l])
                {
                    flag = 0;
                    break;
                }
            }

            if(flag)
                cnt += k;
        }

//        for(auto u : beads)
//            cout << u << endl;
        ret = max(ret, cnt);
    }

//    cout << ret << endl;
    return ret;
}

int main()
{
    int t, n, k, i;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        v = vector<int> (26);
        for(auto u : s)
            v[u - 'a'] ++;

//        beads.clear();
//        for(auto u : v)
//        {
//            if(u > 0)
//                beads.push_back(u);
//        }

        sort(v.begin(), v.end(), greater<int> ());

        int ans = 1;

//        for(auto u : v)
//            cout << u << endl;
//        cout << func(k) << endl;
//            func(6);
        for(i = 1; i * i <= k; i++)
        {
            if(k%i == 0)
            {
//                cout << i << " " << func(i) << " " << func(k/i) << endl;
                ans = max(ans, func(i));
                ans = max(ans, func(k/i));
            }
        }

        cout << ans << endl;
    }
}
