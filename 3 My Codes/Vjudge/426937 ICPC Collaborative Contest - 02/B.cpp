#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno=0;

    double w1, h1, w2, h2, p, q, tr, ans;

    cin >> t;

    while(t--)
    {
        cin >> w1 >> h1 >> w2 >> h2;

        p = max(w1, h1);
        q = min(w1, h1);
        w1 = p;
        h1 = q;

        p = max(w2, h2);
        q = min(w2, h2);
        w2 = p;
        h2 = q;

        if(w1 > w2)
            tr = (w1-w2)*h2/2;
        else
            tr = (w2-w1)*h1/2;

        if(h1 > h2)
            tr = min(tr, (h1-h2)*w2/2);
        else
            tr = min(tr, (h2-h1)*w1/2);

        swap(h2, w2);

        if(w1 > w2)
            tr = min(tr, (w1-w2)*h2/2);
        else
            tr = min(tr, (w2-w1)*h1/2);

        if(h1 > h2)
            tr = min(tr, (h1-h2)*w2/2);
        else
            tr = min(tr, (h2-h1)*w1/2);

        ans = tr + (w1*h1) + (w2*h2);

        cout << fixed;
        cout << setprecision(6) << "Case " << ++caseno << ": " << ans << "\n";
    }
}
