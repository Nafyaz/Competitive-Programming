#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, x = 1, n;
    cin >> n;
    for(i = 0; i < 20; i++)
    {
        cout << i << ": " << x%n << endl;
        x = x * 2;
    }
}
