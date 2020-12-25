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
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

double bc, cd, ad;

double time(double m)
{
    return 2*sqrt(m*m + ad*ad) + sqrt((bc-m)*(bc-m) + cd*cd);
}

double dist(double m)
{
    return sqrt(m*m + ad*ad) + sqrt((bc-m)*(bc-m) + cd*cd);
}

int main()
{
    int t, i;
    double l, h, m1, m2, tm1, tm2;

    cin >> t;

    while(t--)
    {
        cin >> bc >> cd >> ad;

        l = 0, h = bc;

        for(i = 0; i < 10000; i++)
        {
            m1 = l + (h-l)/3;
            m2 = l + (h-l)/3*2;

            tm1 = time(m1);
            tm2 = time(m2);

            if(tm1 < tm2)
                h = m2;
            else
                l = m1;
        }

        cout << fixed;
        cout << setprecision(6) << dist((l+h)/2) << "\n";
    }
}

