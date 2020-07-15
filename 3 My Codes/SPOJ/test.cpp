#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long g, l, i;
    for(i = 1; i < 30; i++)
    {
        if(i == 1)
        {
            g = 1;
            l = 1;
        }
        else
        {
            g = __gcd(l, i);
            l = l*i/g;
        }

        cout << i << " " << l << endl;
    }
}
