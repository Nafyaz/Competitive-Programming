#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1.0)

int main()
{
    long double ab, ad, A, B, bd, bc, ac, ans;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> ab >> ad >> A;
        A = pi*A/180;
        bd = sqrtl(ab*ab + ad*ad - 2*ab*ad*cos(A));
        bc = 2*bd;
        B = asin(ad*sin(A)/bd);
        if(bd*bd + ab*ab < ad*ad)
        {
//            cout << "bd" << bd << " ab" << ab << " ad" << ad << endl;
            B = pi - B;
        }
        ac = sqrtl(ab*ab + bc*bc - 2*ab*bc*cos(B));

        cout.precision(9);
        ans = ab*ab + ac*ac;
        cout << fixed << ans << endl;
    }
}
