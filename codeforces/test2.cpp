#include<bits/stdc++.h>
using namespace std;

bool f1(int a, int b, int c)
{
    if(a == 2 && b != 9 && c != 1)
        return 1;
    if(a != 2 && b == 9 && c != 1)
        return 1;
    if(a != 2 && b != 9 && c == 1)
        return 1;
    return 0;
}
bool f2(int a, int b, int c)
{
    int x = 2, y = 4, z = 5;
    if(a == y && (b != x || c != x || b != z || c != z))
        return 1;
    x = 2, y = 5, z = 4;
    if(a == y && (b != x || c != x || b != z || c != z))
        return 1;
    x = 4, y = 2, z = 5;
    if(a == y && (b != x || c != x || b != z || c != z))
        return 1;
    x = 4, y = 5, z = 2;
    if(a == y && (b != x || c != x || b != z || c != z))
        return 1;
    x = 5, y = 2, z = 4;
    if(a == y && (b != x || c != x || b != z || c != z))
        return 1;
    x = 5, y = 4, z = 2;
    if(a == y && (b != x || c != x || b != z || c != z))
        return 1;
    return 0;
}
bool f3(int a, int b, int c)
{
    int a[3] = {4, 6, 3};
    do
    {
        if()
    }
}

int main()
{
    int a, b, c;
    for(a = 1; a <= 9; a++)
    {
        for(b = 1; b <= 9; b++)
        {
            for(c = 1; c <= 9; c++)
                if(f1(a, b, c) && f2(a, b, c) && f3(a, b, c) && f4(a, b, c))
                    cout << a << " " << b << " " << c << endl;
        }
    }
}
