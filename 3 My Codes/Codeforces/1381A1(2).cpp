#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i;
    string a, b;

    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b;
        vector<int> ans;
        for(i = 0; i < n; i++)
        {
            if(a[i] != b[i])
            {
                ans.push_back(i+1);
                ans.push_back(1);
                ans.push_back(i+1);
            }
        }

        cout << ans.size() << " ";
        for(i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
