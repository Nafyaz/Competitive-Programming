#include<bits/stdc++.h>
using namespace std;

int BIT[100][100];

void update(int x, int y, int val)
{
    int y1;
    while (x <= max_x)
    {
        y1 = y;
        while (y1 <= max_y)
        {
            BIT[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}
int query(int x, int y)
{
    int y1, sum = 0;
    while(x)
    {
        y1 = y;
        while(y1)
        {
            sum += BIT[x][y1];
            y1 -= y1&(-y1);
        }
        x -= x&(-x);
    }
    return sum;
}

int main()
{

}
