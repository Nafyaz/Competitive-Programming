#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, j, a, cnt;
    cin >> t;
    while(t--)
    {
        vector<int> o, e;
        cin >> n;
        for(i = 0; i < 2 * n; i++)
        {
            cin >> a;
            if(a&1)
                o.push_back(i+1);
            else
                e.push_back(i+1);
        }

        cnt = 0;
        for(i = 0; i + 1 < o.size() && cnt < n - 1; i += 2)
        {
            cout << o[i] << " " << o[i+1] << endl;
            cnt++;
        }

        for(i = 0; i < e.size() && cnt < n - 1; i += 2)
        {
            cout << e[i] << " " << e[i+1] << endl;
            cnt++;
        }
    }
}
