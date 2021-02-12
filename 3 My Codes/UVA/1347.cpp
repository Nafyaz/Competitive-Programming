#include<bits/stdc++.h>
using namespace std;

class point
{
public:
    int x, y;
    double dist(point p)
    {
        return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
    }
};

int n, visited[1009];
point p[1009];

double call(int i)
{
    int j, k;
    double ret = 0;
    if(i == n-1)
    {
        k = n-1;
        for(j = n-1; j > 0; j--)
        {
            if(!visited[j])
            {
                ret = ret + p[k].dist(p[j]);
                k = j;
            }
        }

        return ret;
    }


}

int main()
{
    int i;

    while(cin >> n)
    {
        for(i = 0; i < n; i++)
        {
            cin >> p[i].x >> p[i].y;
            visited[i] = 0;
        }

        call()
    }
}
