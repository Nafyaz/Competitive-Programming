#include<bits/stdc++.h>
using namespace std;

int a[100009], dis[100009];
vector <int> sticks;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, caseno = 0, n, m, i, j;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;

        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        for(i = 0; i < n; i++)
        {
            if(i == 0)
                dis[0] = a[i];
            else
                dis[i] = a[i] - a[i-1];
        }

        dis[n] = m - a[n-1];

        sticks.clear();
        sticks.push_back(INT_MIN);

        for(i = 0; i <= n; i++)
        {
            for(j = 1; j < dis[i]; j++)
            {
                if(j >= sticks.size())
                    sticks.push_back ( -((dis[i] + j - 1) / j - 1));
                else
                    sticks[j] -= ((dis[i] + j - 1) / j - 1);
            }
        }

//        for(i = 0; i < sticks.size(); i++)
//            cout << sticks[i] << " ";
//        cout << endl;

//        reverse(sticks.begin(), sticks.end());

        cout << "Case " << ++caseno << ": \n";
        int q, s;
        cin >> q;
        while(q--)
        {
            cin >> s;

            cout << (lower_bound(sticks.begin(), sticks.end(), -s) - sticks.begin()) << "\n";
        }

    }
}
