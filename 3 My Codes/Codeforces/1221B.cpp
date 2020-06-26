#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if((i+j) & 1)
                cout << "B";
            else
                cout << "W";
        }
        cout << endl;
    }
}
