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
    int n, i, x, low = INT_MAX, high = INT_MIN, lowcount, highcount, lowidx, highidx;
    cin >> n;
    int a[n];

    ordered_set <int> vol;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        vol.insert(a[i]);

        if(low > a[i])
        {
            low = a[i];
            lowidx = i;
            lowcount = 1;
        }
        else if(low == a[i])
            lowcount++;

        if(high < a[i])
        {
            high = a[i];
            highidx = i;
            highcount = 1;
        }
        else if(high == a[i])
            highcount++;
    }

    if(low == high)
        cout << "Exemplary pages.";
    else if(vol.size() == 2)
    {
        if(lowcount == 1 && highcount == 1 && (low + high)%2 == 0)
            cout << (high - low)/2 <<" ml. from cup #"<< lowidx +1<<" to cup #" << highidx +1<< ".";
        else
            cout << "Unrecoverable configuration.";
    }
    else if(vol.size() == 3)
    {
        int p = (high - low)/2;

        if(lowcount == 1 && highcount == 1 && 2*p == high - low && low + p == *(vol.find_by_order(1)))
            cout << p <<" ml. from cup #"<< lowidx +1<<" to cup #" << highidx +1<< ".";
        else
            cout << "Unrecoverable configuration.";
    }
    else
        cout << "Unrecoverable configuration.";
}
