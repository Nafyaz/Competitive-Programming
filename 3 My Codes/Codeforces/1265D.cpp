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

int main()
{
    int i, a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = a+b+c+d;
    string s(n, 'x'), t(n, 'x');
    int a1 = a, b1 = b, c1 = c, d1 = d;


    for(i = 0; i < n; i++)
    {
        if(i%2 == 0)
        {
            if(a1)
            {
                s[i] = '0';
                a1--;
            }
            else if(c1)
            {
                s[i] = '2';
                c1--;
            }
//            else
//            {
//                cout << "NO";
//                return 0;
//            }
        }
        else
        {
            if(b1)
            {
                s[i] = '1';
                b1--;
            }
            else if(d1)
            {
                s[i] = '3';
                d1--;
            }
//            else
//            {
//                cout << "NO";
//                return 0;
//            }
        }
    }

    a1 = a, b1 = b, c1 = c, d1 = d;
    for(i = 0; i < n; i++)
    {
        if(i%2 == 0)
        {
            if(b1)
            {
                t[i] = '1';
                b1--;
            }
            else if(d1)
            {
                t[i] = '3';
                d1--;
            }
        }
        else
        {
            if(a1)
            {
                t[i] = '0';
                a1--;
            }
            else if(c1)
            {
                t[i] = '2';
                c1--;
            }
        }
    }

    int tright = 1, sright = 1;
    for(i = 0; i < n; i++)
    {
        if(t[i] == 'x')
            tright = 0;
        if(s[i] == 'x')
            sright = 0;
        if(i > 0 && abs(t[i] - t[i-1]) != 1)
            tright = 0;
        if(i > 0 && abs(s[i] - s[i-1]) != 1)
            sright = 0;
    }

    if(sright)
    {
        cout << "YES" << endl;
        for(auto u : s)
            cout << u << " ";
    }
    else if(tright)
    {
        cout << "YES" << endl;
        for(auto u : t)
            cout << u << " ";
    }
    else
        cout << "NO";
}
