#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, caseno = 0, a, b;

    cin >> T;

    while(T--)
    {
        cin >> a >> b;

        cout << "Case " << ++caseno << ": " << (a*b) / (b-a) << "\n";
    }
}
