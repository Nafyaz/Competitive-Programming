#include<bits/stdc++.h>
using namespace std;

int val[200005];
int prefMin[200005], prefMax[200005];
int suffMin[200005], suffMax[200005];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int T, n, m, l, r, i, total, temp, mn, mx;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n >> m >> s;

        for(i = 1; i <= n; i++)
        {
            if(s[i-1] == '+')
                val[i] = val[i-1] + 1;
            else
                val[i] = val[i-1] - 1;

            prefMin[i] = min(prefMin[i-1], val[i]);
            prefMax[i] = max(prefMax[i-1], val[i]);
        }

        total = val[n];
        temp = 0;
        suffMin[n+1] = suffMax[n+1] = 0;
        for(i = n; i >= 1; i--)
        {
            if(s[i-1] == '+')
                temp = temp + 1;
            else
                temp = temp - 1;

            suffMin[i] = min(suffMin[i+1], temp);
            suffMax[i] = max(suffMax[i+1], temp);
        }

//        for(i = 0; i <= n; i++)
//            cout << setw(3) << suffMin[i] << setw(3) << suffMax[i] << "\n";

        cout << prefMin[1] << " " << suffMin[6] + total << "; " << prefMax[1] << " " << suffMax[6] - val[5] - val[1] << "\n";

        while(m--)
        {
            cin >> l >> r;

            mn = prefMin[l-1];
            if(r < n)
                mn = min(mn, suffMin[r+1] - val[r] + val[l-1]);

            mx = prefMax[l-1];
            if(r < n)
                mx = max(mx, suffMax[r+1] - val[r] + val[l-1]);

            cout << mx - mn + 1 << "\n";
        }
    }
}
