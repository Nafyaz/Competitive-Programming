#include<bits/stdc++.h>
using namespace std;

int main()
{
    int o = 0, m = -1, z = 0, x, n;
    cin >> n;
    while(n--)
    {
        cin >> x;
        if(x == 1)
        {
            o++;
            if(z > 0)
                z--;
        }
        else
        {
            z++;
            if(z > m)
                m=z;
        }
    }

    cout << o + m << endl;
    return 0;
}
