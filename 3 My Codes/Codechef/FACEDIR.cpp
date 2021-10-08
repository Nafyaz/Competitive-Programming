#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;

    cin >> t;

    while(t--)
    {
        cin >> n;

        switch(n%4)
        {
        case 0:
            cout << "NORTH\n";
            break;
        case 1:
            cout << "EAST\n";
            break;
        case 2:
            cout << "SOUTH\n";
            break;
        case 3:
            cout << "WEST\n";
        }
    }
}
