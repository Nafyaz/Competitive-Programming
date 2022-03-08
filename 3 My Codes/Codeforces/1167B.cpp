#include<bits/stdc++.h>
using namespace std;

int a, b, c, d;

bool findA0(int x)
{
    return (a%x == 0 && b%x == 0 && c%x == 0 && d%x == 0);
}

int main()
{
    int i, ans[6];

    cout << "? 1 2\n";
    cin >> a;
    cout << "? 1 3\n";
    cin >> b;
    cout << "? 1 4\n";
    cin >> c;
    cout << "? 1 5\n";
    cin >> d;

    if(findA0(42))
        ans[0] = 42;
    else if(findA0(23))
        ans[0] = 23;
    else if(findA0(16))
        ans[0] = 16;
    else if(findA0(15))
        ans[0] = 15;
    else if(findA0(8))
        ans[0] = 8;
    else if(findA0(4))
        ans[0] = 4;

    ans[1] = a/ans[0];
    ans[2] = b/ans[0];
    ans[3] = c/ans[0];
    ans[4] = d/ans[0];

    ans[5] = 7418880/ans[0]/ans[1]/ans[2]/ans[3]/ans[4];

    cout << "! ";
    for(i = 0; i < 6; i++)
        cout << ans[i] << " ";
}
