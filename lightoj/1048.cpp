#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno = 0, i, ans;
    int a[1009] = {0}, pre[1009] = {0}, n, k, mn;
    scanf("%d", &t);
    while(t--)
    {
        mn = INT_MAX;
        scanf("%d %d", &n, &k);
        n++;
        k++;

        for(i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            pre[i] = pre[i-1] + a[i];
        }

        int pos, prepos, low, high, mid, cnt;
        vector<int> v;
        low = 1;
        high = pre[n];
        while(low <= high)
        {
            v.clear();
            mid = (low + high)>>1;
            cnt = 0;
//            cout << "mid: " << mid << endl;
            prepos = pos = 0;
            while(pos <= n)
            {
                pos = upper_bound(pre, pre+n+1, mid + pre[prepos]) - pre - 1;
//                cout << prepos << " " << pos << " " << mid + pre[prepos] << endl;
                if(pos == prepos)
                    break;
                v.push_back(pre[pos] - pre[prepos]);
                prepos = pos;
                cnt++;
            }
            if(prepos != n || cnt > k)
                low = mid+1;
            else
            {
                high = mid-1;
                ans = mid;
            }
        }
        printf("Case %d: %d\n", ++caseno, ans);
        for(auto u : v)
            printf("%d\n", u);
    }
}
