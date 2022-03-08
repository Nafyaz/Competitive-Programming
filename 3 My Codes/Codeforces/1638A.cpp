#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, i, l, r;
    int p[502];

    cin >> T;

    while(T--)
    {
        cin >> n;

        l = -1;
        r = -1;
        for(i = 1; i <= n; i++)
        {
            cin >> p[i];
            if(l == -1 && p[i] > i)
                l = i;
            if(p[i] == l)
                r = i;
        }

        reverse(p+l, p+r+1);

        for(i = 1; i <= n; i++)
            cout << p[i] << " ";
        cout << "\n";
    }
}
