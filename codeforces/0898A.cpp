#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    x - x/10*10 > (x+10)/10*10 - x? cout << (x+10)/10*10 : cout << x/10*10;
}
