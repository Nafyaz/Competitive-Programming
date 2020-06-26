#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i, n, k, s[10009];
    deque<int> d;
    cin >> t;
    while(t--)
    {
        d.clear();
        cin >> n >> k;

        for(i = 0; i < n; i++)
        {
            cin >> s[i];
            while(!d.empty() && s[d.back()] <= s[i])
                d.pop_back();
            d.push_back(i);

            if(d.front() == i-k)
                d.pop_front();
            if(i >= k-1)
                cout << s[d.front()] << " ";
        }

        cout << endl;
    }
}
