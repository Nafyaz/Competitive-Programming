#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, caseno = 0, n, k, p;

    cin >> T;

    while(T--)
    {
        cin >> n >> k >> p;

        cout << "Case " << ++caseno << ": " << (k-1+p)%n+1 << "\n";
    }
}
