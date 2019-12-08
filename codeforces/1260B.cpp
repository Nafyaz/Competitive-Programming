#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, t, sum;

    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        sum = a+b;
        if(sum%3 != 0)
        {
            cout << "NO" << endl;
            continue;
        }

        sum /= 3;
        if(min(a, b) >= sum && max(a, b) <= 2*sum)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

}
