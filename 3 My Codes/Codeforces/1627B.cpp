#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans;

int findMax(int i, int j)
{
    int ret = -1;
    ret = max(ret, i+j);
    ret = max(ret, n-i-1 + j);
    ret = max(ret, i + m-j-1);
    ret = max(ret, n-i-1 + m-j-1);

    return ret;
}

int main()
{
    int t, i, j;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        ans.clear();
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
                ans.push_back(findMax(i, j));
        }

        sort(ans.begin(), ans.end());

        for(auto u : ans)
            cout << u << " ";
        cout << "\n";
    }
}
