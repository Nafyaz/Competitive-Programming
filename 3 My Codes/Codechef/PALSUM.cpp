#include<bits/stdc++.h>
using namespace std;

bool is_good(int n)
{
    string bin = "", rev_bin;
    while(n)
    {
        if(n&1)
            bin.push_back('1');
        else
            bin.push_back('0');
        n /= 2;
    }

    rev_bin = bin;
    reverse(rev_bin.begin(), rev_bin.end());

    return bin == rev_bin;
}

int main()
{
    int T, n, i, val;

    vector<int> goods, ans;

    for(i = 1; i <= 1000; i++)
    {
        if(is_good(i))
            goods.push_back(i);
    }

    cin >> T;

    while(T--)
    {
        cin >> n;

        ans.clear();
        while(n)
        {
            val = upper_bound(goods.begin(), goods.end(), n) - goods.begin();
            ans.push_back(goods[val-1]);

            n -= goods[val-1];
        }

        cout << ans.size() << "\n";
        for(auto u : ans)
            cout << u << " ";
        cout << "\n";
    }
}
