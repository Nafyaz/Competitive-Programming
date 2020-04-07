#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << "YES" << endl;
        cout << "0 0";
    }
    else if(n == 2)
    {
        cout << "YES" << endl;
        cout << "0 0" << endl;
        cout << "1 0" << endl;
    }
    else if(n == 4)
    {
        cout << "YES" << endl;
        cout << "0 0" << endl;
        cout << "0 1" << endl;
        cout << "1 1" << endl;
        cout << "1 0" << endl;
    }
    else
        cout << "NO" << endl;
}
