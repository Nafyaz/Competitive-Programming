#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, caseno = 0;
    double ab, ac, bc, r;

    cin >> t;
    while(t--)
    {
        cin >> ab >> ac >> bc >> r;
        cout << fixed;
        cout << "Case " << ++caseno << ": " << setprecision(7) << sqrt(ab*ab*r/(1+r)) << "\n";
    }
}
