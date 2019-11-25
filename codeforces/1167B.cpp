#include<bits/stdc++.h>
using namespace std;

int a[6] = {4, 8, 15, 16, 23, 42}, b[6];
pair <int, int> func(int x)
{
    int flag = 0;
    pair <int, int> p;

    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if(allpair[i][j] == x)
            {
                p.first = a[i];
                p.second = a[j];
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }
    return p;
}



int main()
{
    int allpair[6][6];
    int i, j, x, y, flag1, flag2;

    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < 6; j++)
            allpair[i][j] = a[i] * a[j];
    }

    cout << '!' << 1 << " " << 2 << endl;
    cin << x;
    cout << '!' << 1 << " " << 3 << endl;
    cin << y;



}
