#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, b1, b2, m1, m2, l, r;
    cin >> t;
    while(t--)
    {
        cin >> b1 >> b2 >> m1 >> m2;
        if(b2 < b1)
            swap(b1, b2);
        if(m2 < m1)
            swap(m1, m2);

        l = min(b2, m2);
        r = max(b1, m1);

        if(l < r)
            cout << "Line" << endl;
        else if(l > r)
            cout << "Nothing" << endl;
        else
            cout << "Point" << endl;
    }
}
