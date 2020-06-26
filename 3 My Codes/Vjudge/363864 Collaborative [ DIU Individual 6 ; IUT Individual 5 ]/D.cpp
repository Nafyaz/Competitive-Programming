#include<bits/stdc++.h>
using namespace std;

int a[1009], n, i, j;

int main()
{
    int x[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

    for(auto u : x)
    {
        for(i = 1; u*i < 1009; i++)
            a[u*i] = 1;
    }

    cin >> n;

    cout << (a[n]? "YES" : "NO") << endl;
}
