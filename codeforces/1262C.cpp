//Thanks to shahed_ahmed and msi1427
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int t, i, j, n, k;
    string s, s2;
    queue <pair<int, int> > q;
    cin >> t;
    while(t--)
    {
        s2.clear();
        while(!q.empty())
            q.pop();

        cin >> n >> k >> s;
        while(k > 1)
        {
            s2 += "()";
            k--;
        }

        int temp = s.size() - s2.size();
        for(i = 1; i <= temp; i++)
            s2 += ( i <= temp /2 ? '(' : ')' );

//        cout << s2 << endl;
        for(i = 0; i < n; i++)
        {
            if(s[i] == s2[i])
                continue;

            j = i + 1;
            while(j < n && s[i] == s[j])
                j++;

            q.push({i+1, j+1});

            reverse(s.begin() + i, s.begin() + j + 1);
        }

        cout << q.size() << endl;
        while(!q.empty())
        {
            cout << q.front().ff << " " << q.front().ss << endl;
            q.pop();
        }
    }
}
