#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, n, i, h, a, prev;

    cin >> t;

    while(t--)
    {
        cin >> n;

        prev = 0;
        h = 1;

        for(i = 0; i < n; i++)
        {
            cin >> a;

            if(h == -1)
                continue;

            if(i > 0 && prev == 0 && a == 0)
                h = -1;
            else if(prev == 0 && a == 1)
                h++;
            else if(prev == 1 && a == 1)
                h += 5;

            prev = a;
        }

        cout << h << "\n";
    }
}
