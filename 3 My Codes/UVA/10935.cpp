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
    int n, i;
    deque<int> d;
    queue<int> q;
    while(1)
    {
        cin >> n;
        if(n == 0)
            break;

        for(i = 1; i <= n; i++)
            d.push_back(i);

        while(d.size() > 2)
        {
            q.push(d.front());
            d.pop_front();
            d.push_back(d.front());
            d.pop_front();
        }
        if(d.size() > 1)
        {
            q.push(d.front());
            d.pop_front();
        }

        cout << "Discarded cards:";
        i = 0;
        while(!q.empty())
        {
            cout << " " << q.front();
            q.pop();
            if(!q.empty())
                cout << ",";
            i++;
        }
        cout << endl << "Remaining card: " << d.front() << endl;
        d.pop_front();
    }
}

