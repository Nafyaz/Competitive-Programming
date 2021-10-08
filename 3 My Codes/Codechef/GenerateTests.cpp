#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "w", stdout);

    int q = 50*50, i, j;

    cout << q << "\n";

    for(i = 2; i <= 51; i++)
    {
        for(j = 2; j < i; j++)
        {
            cout << i << " " << 2 << " " << j << "\n";
        }
    }
}
