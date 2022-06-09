int mx = 100, my = 100;
BIT[mx][my];

void update(int x, int y, int val)
{
    int y1;
    while (x <= mx)
    {
        y1 = y;
        while (y1 <= my)
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