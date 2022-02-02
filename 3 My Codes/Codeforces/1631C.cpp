#include<bits/stdc++.h>
using namespace std;

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t, i, n, k, kPair, p1, p2;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        if(n == 4 && k == 3)
        {
            cout << "-1\n";
            continue;
        }

        if(k != n-1)
        {
            kPair = (k^(n-1));

            for(i = 0; i < n/2; i++)
            {
                p1 = i;
                p2 = n-1-i;

                if(i == 0)
                    cout << p1 << " " << kPair << "\n";
                else if(p1 == k)
                    cout << p1 << " " << n-1 << "\n";
                else if(p2 == k)
                    cout << n-1 << " " << p2 << "\n";
                else
                    cout << p1 << " " << p2 << "\n";
            }
        }

        else
        {
            for(i = 0; i < n/2; i++)
            {
                p1 = i;
                p2 = n-1-i;

                if(i == 0)
                    cout << 0 << " " << ((n-1)^3) << "\n";
                else if(i == 1)
                    cout << "1 3\n";
                else if(i == 3)
                    cout << n-2 << " " << n-1 << "\n";
                else
                    cout << p1 << " " << p2 << "\n";
            }
        }

    }
}
