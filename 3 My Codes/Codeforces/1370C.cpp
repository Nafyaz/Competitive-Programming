#include<bits/stdc++.h>
using namespace std;

bool func(int n)
{
    if(n <= 2 || (n&1) || (n&(n-1)) == 0)
        return 1;
    return 0;
}

string Find(int n)
{
    if(((n&1) && n != 1) || n == 2)
        return "Ashishgup\n";
    return "FastestFinger\n";
}

int cnt(int n)
{
    int ret = 0;
    while(n%2 == 0)
    {
        ret++;
        n /= 2;
    }
    return ret;
}
int main()
{
    int t, n, i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(func(n))
            cout << Find(n);
        else if(cnt(n) == 1)
            cout << "FastestFinger\n";
        else
            cout << "Ashishgup\n";
    }
}
