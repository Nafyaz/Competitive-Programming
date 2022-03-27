#include<bits/stdc++.h>
using namespace std;
#define ll long long

class logo
{
    ll mnL, mxL;
    char c;
};

ll sq;
logo L[3];



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x1, y1, x2, y2, x3, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    ll sum = x1*y1 + x2*y2 + x3*y3;
    sq = sqrt(sum);

    if(sq*sq != sum)
    {
        cout << -1;
        return 0;
    }

    L[0].mnL = min(x1, y1);
    L[0].mxL = max(x1, y1);
    L[0].c = 'A';

    L[1].mnL = min(x2, y2);
    L[1].mxL = max(x2, y2);
    L[1].c = 'B';

    L[2].mnL = min(x3, y3);
    L[2].mxL = max(x3, y3);
    L[2].c = 'C';

    if(L[0].mxL >= L[1].mxL && L[0].mxL >= L[2].mxL)
    {

    }
}
