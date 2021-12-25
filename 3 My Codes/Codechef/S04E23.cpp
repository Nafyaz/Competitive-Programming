#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, p, q, i, dim[2], d;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n >> p >> q >> s;

        p = abs(p);
        q = abs(q);

        dim[0] = dim[1] = 0;

        for(i = d = 0; i < n; i++)
        {
            if(s[i] == '0')
                d ^= 1;

            dim[d]++;
        }

        if(dim[0] >= p && dim[1] >= q && dim[0]%2 == p%2 && dim[1]%2 == q%2)
            cout << "YES\n";
        else if(dim[0] >= q && dim[1] >= p && dim[0]%2 == q%2 && dim[1]%2 == p%2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
