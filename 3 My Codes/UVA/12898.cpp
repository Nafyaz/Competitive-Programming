#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, caseno = 0, a, b, i, Or, And;
    cin >> t;
    while(t--)
    {
        Or = And = 0;
        cin >> a >> b;
        for(i = 1; i <= b; i = (i << 1))
        {
            if((a&i) || (b&i) || (b-a-1) >= i)
                Or |= i;
            if((a&i) && (b&i) && (b-a-1) < i)
                And |= i;
        }

        cout << "Case " << ++caseno << ": " << Or << " " << And << "\n";
    }
}
