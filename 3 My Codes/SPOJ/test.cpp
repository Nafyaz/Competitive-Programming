#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p = 13, i = 2;
    cout << (int)log10(p) + 1 << endl;
    cout << (int)pow(10, (int)log10(p) + 1) << endl;
    cout << (int)pow(10, (int)log10(p) + 1)*i + p;
}
