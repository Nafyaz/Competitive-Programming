#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a > b)
            swap(a, b);
        cout << (2*a < a+b? max(2*a, b)*max(2*a, b) : max(a+b, b)*max(a+b, b)) << endl;
    }
}
