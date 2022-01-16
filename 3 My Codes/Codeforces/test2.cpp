#include<bits/stdc++.h>
using namespace std;


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);

    int T;
    string S;
    cin >> T;

    while(T--)
    {
        cin >> S;
        cout << "Case: " << T << "\n";
        int n, i, t, d, currD, ans;

        queue<int> q[2];
        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> t >> d;

            q[d].push(t);
        }

        if(!q[0].empty() && !q[1].empty())
        {
            if(q[0].front() > q[1].front())
            {
                currD = 1;
                ans = q[1].front() + 10;
            }
            else
            {
                currD = 0;
                ans = q[0].front() + 10;
            }
        }
        else if(!q[0].empty())
        {
            currD = 0;
            ans = q[0].front() + 10;
        }
        else
        {
            currD = 1;
            ans = q[1].front() + 10;
        }


        while(!q[0].empty() && !q[1].empty())
        {
            if(ans >= q[currD].front() || q[currD].front() < q[currD^1].front())
            {
                ans = max(ans, q[currD].front()+10);
                q[currD].pop();
            }

            else
            {
                currD ^= 1;
                ans = max(ans, q[currD].front())+10;
                q[currD].pop();
            }
        }

        while(!q[currD].empty())
        {
            ans = max(ans, q[currD].front()+10);
            q[currD].pop();
        }

        currD ^= 1;
        if(!q[currD].empty())
        {
            ans = max(ans, q[currD].front())+10;
            q[currD].pop();
        }

        while(!q[currD].empty())
        {
            ans = max(ans, q[currD].front()+10);
            q[currD].pop();
        }

        cout << ans << "\n";
    }
}
