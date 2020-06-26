#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

char temp;
vector<int> v[4];

void func(int x0, int y0, int xd, int yd, int num)
{
    if(x0 == xd && yd > y0)
    {
        if(temp == 'E')
        {
            v[num].push_back(-1);
            v[num].push_back(-1);
            v[num].push_back(-1);
        }
        if(temp == 'S')
        {
            v[num].push_back(-1);
            v[num].push_back(-1);
        }
        if(temp == 'W')
        {
            v[num].push_back(-1);
        }
        v[num].push_back(yd - y0);
        if(v[num].size())
            temp = 'N';
    }

    if(x0 == xd && yd < y0)
    {
        if(temp == 'W')
        {
            v[num].push_back(-1);
            v[num].push_back(-1);
            v[num].push_back(-1);
        }
        if(temp == 'N')
        {
            v[num].push_back(-1);
            v[num].push_back(-1);
        }
        if(temp == 'E')
        {
            v[num].push_back(-1);
        }
        v[num].push_back(y0 - yd);
        if(v[num].size())
            temp = 'S';
    }

    if(y0 == yd && xd > x0)
    {
        if(temp == 'S')
        {
            v[num].push_back(-1);
            v[num].push_back(-1);
            v[num].push_back(-1);
        }
        if(temp == 'W')
        {
            v[num].push_back(-1);
            v[num].push_back(-1);
        }
        if(temp == 'N')
        {
            v[num].push_back(-1);
        }
        v[num].push_back(xd - x0);
        if(v[num].size())
            temp = 'E';
    }

    if(y0 == yd && xd < x0)
    {
        if(temp == 'N')
        {
            v[num].push_back(-1);
            v[num].push_back(-1);
            v[num].push_back(-1);
        }
        if(temp == 'E')
        {
            v[num].push_back(-1);
            v[num].push_back(-1);
        }
        if(temp == 'S')
        {
            v[num].push_back(-1);
        }
        v[num].push_back(x0 - xd);
        if(v[num].size())
            temp = 'W';
    }
}

int main()
{
    int x0, y0, xd, yd;
    char dir;
    cin >> x0 >> y0 >> dir >> xd >> yd;

    temp = dir;
    func(x0, y0, x0, yd, 0);
    func(x0, yd, xd, yd, 1);

    temp = dir;
    func(x0, y0, xd, y0, 2);
    func(xd, y0, xd, yd, 3);

    if(v[0].size() + v[1].size() < v[2].size() + v[3].size())
    {
        cout << v[0].size() + v[1].size() << endl;
        for(auto u : v[0])
        {
            if(u == -1)
                cout << 'D' << endl;
            else
                cout << "A " << u << endl;
        }
        for(auto u : v[1])
        {
            if(u == -1)
                cout << 'D' << endl;
            else
                cout << "A " << u << endl;
        }
    }

    else
    {
        cout << v[2].size() + v[3].size() << endl;
        for(auto u : v[2])
        {
            if(u == -1)
                cout << 'D' << endl;
            else
                cout << "A " << u << endl;
        }
        for(auto u : v[3])
        {
            if(u == -1)
                cout << 'D' << endl;
            else
                cout << "A " << u << endl;
        }
    }
}
