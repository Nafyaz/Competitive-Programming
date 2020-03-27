#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 1)
        cout << 1;
    else
        cout << (int)log2(n-1) + 2;
}
