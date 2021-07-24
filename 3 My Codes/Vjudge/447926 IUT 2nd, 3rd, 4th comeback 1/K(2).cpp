#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, k;
ll c[20];
vector<int> subsetSum;

bool func(ll i, ll sum)
{
    if(sum == k || 2*sum == k)
        return 1;
    if(sum > k)
        return 0;
    if(i == n)
    {
        subsetSum.push_back(sum);
        return 0;
    }

    if(func(i+1, sum) == 1)
        return 1;
    if(func(i+1, sum+c[i]) == 1)
        return 1;

    return 0;
}

int main()
{
    ll t, caseno = 0, i, rest, pos, flag;

    cin >> t;

    while(t--)
    {
        subsetSum.clear();
        cin >> n >> k;

        for(i = 0; i < n; i++)
            cin >> c[i];

        cout << "Case " << ++caseno << ": ";

        if(func(0, 0) == 1)
        {
            cout << "Yes\n";
            continue;
        }

        sort(subsetSum.begin(), subsetSum.end());

        flag = 0;
        for(i = 0; i < subsetSum.size() && !flag; i++)
        {
            rest = k - subsetSum[i];
            pos = lower_bound(subsetSum.begin(), subsetSum.end(), rest) - subsetSum.begin();
//            cout << rest << " " << pos << "\n";

            if(pos < subsetSum.size() && subsetSum[pos] == rest)
                flag = 1;
        }

        cout << (flag? "Yes\n" : "No\n");
    }
}
