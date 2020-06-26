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
    int t, n, i, j, flag1, flag2;
    cin >> t;
    while(t--)
    {
        stack<int> s;
        cin >> n;

        for(i = 2; i <= sqrt(n); i++)
        {
            j = n;
            while(j)
            {
                s.push(j%i);
                j /= i;
            }

            flag1 = flag2 = 0;
            cout << i << ": " << (n%(i*i) >= i) << "|||";
            while(!s.empty())
            {
                if(s.size() == 2 && s.top() == 0)
                    flag1 = 1;
                if(s.size() == 1 && s.top() != 0)
                    flag2 = 1;

                cout << setw(3) << s.top();
                s.pop();
            }

            if(flag1 && flag2)
                cout << "here it is";
            cout << endl;
        }
    }
}
