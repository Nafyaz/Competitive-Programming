#include<bits/stdc++.h>
using namespace std;

int a[200005];
deque<int> p;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int T, n, i, j;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            cin >> a[i];

        if(a[1] != n && a[n] != n)
            cout << "-1\n";
        else
        {
            p.clear();

            i = 1;
            j = n;
            while(i <= j)
            {
                if(a[i] > a[j])
                {
                    p.push_front(a[i]);
                    i++;
                }
                else
                {
                    p.push_back(a[j]);
                    j--;
                }
            }

            for(auto u : p)
                cout << u << " ";
            cout << "\n";

        }

    }
}
