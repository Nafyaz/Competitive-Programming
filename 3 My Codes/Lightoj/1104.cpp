#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, m, n, caseno = 0;

    cin >> t;

    while(t--)
    {
        cin >> n;

        double p = 1;

        for(m = 1; p > 0.5; m++)
        {
            p *= (n-m);
            p /= n;
        }

        cout << "Case " << ++caseno << ": " << m-1 << "\n";
    }
}
