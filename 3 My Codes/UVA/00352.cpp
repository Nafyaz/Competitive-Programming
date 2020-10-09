/*
Check and remove this section while coding
1. Get rid of toolbars except compiler and main. Enable only logs and status.
2. Use C++17 in global compiler settings.
3. Turn on Wall, Wextra, Wshadow in warnings.
4. Make tab spout 4 spaces
*/

/*
ID: nafis.f1
TASK:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second
#define pb push_back

int m, n;
string field[25];

void func(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= n)
        return;

    if(field[i][j] == '0')
        return;

    field[i][j] = '0';

    func(i, j-1); func(i, j+1);
    func(i-1, j); func(i+1, j);

    func(i-1, j-1); func(i+1, j+1);
    func(i-1, j+1); func(i+1, j-1);
}

int main()
{
    int i, j, ans, caseno = 0;

    while(cin >> n)
    {
        ans = 0;
        for(i = 0; i < n; i++)
            cin >> field[i];

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(field[i][j] == '1')
                {
                    ans++;
                    func(i, j);
                }
            }
        }

        cout << "Image number " << ++caseno << " contains " << ans << " war eagles.\n";

    }
}

