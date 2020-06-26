#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, p[109], c[109], prevp, prevc, i, f;
    cin >> t;
    while(t--)
    {
        f = 1;
        cin >> n;
        prevp = 0;
        prevc = 0;
        for(i = 0; i < n; i++)
        {
            cin >> p[i] >> c[i];
            if(p[i] - prevp < c[i] - prevc)
                f = 0;
            if(p[i] < c[i])
                f = 0;

            prevp = p[i];
            prevc = c[i];
        }

        if(!is_sorted(p, p+n) || !is_sorted(c, c+n))
            f = 0;

        cout << (f? "YES" : "NO") << endl;
    }
}
