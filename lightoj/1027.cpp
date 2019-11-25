#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, caseno = 0, n, x[101], i, posC, sum;
    cin >> t;
    while(t--)
    {
        cin >> n;

        sum = posC = 0;
        for(i = 0; i < n; i++)
        {
            cin >> x[i];
            if(x[i] > 0)
                posC ++;
            else
                x[i] = -x[i];

            sum += x[i];
        }

        i = __gcd(sum, posC);
        sum /= i;
        posC /= i;

        cout << "Case " << ++caseno << ": ";
        posC? cout << sum << "/" << posC : cout << "inf";
        cout << endl;
    }
}
