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

int ans[500000];

void p(stack<int> pq)
{
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main()
{
    int n, i, x;
    char br;
    stack<int> st;

    cin >> n;
    scanf("%c", &br);

    while(1)
    {
        x = 0;
        scanf("%c", &br);
        while(br >= '0' && br <= '9')
        {
            x = 10*x + (br - '0');
            scanf("%c", &br);
        }
        if(x != 0)
            st.push(x);

        if(br == ')')
        {
            x = st.top();
            st.pop();
            ans[x] = st.top();
        }

        if(br == '\n')
            break;
    }

    for(i = 1; i <= n; i++)
        cout << ans[i] << " ";

}
