#include<bits/stdc++.h>
using namespace std;

int a[30], n;
string s[30];

int hist()
{
    int i, left[30], right[30];
    stack<int> st;

    memset(left, 0, sizeof left);
    for(i = 0; i < n; i++)
    {
        while(!st.empty() && a[st.top()] >= a[i])
        {
            left[i] += left[st.top()];
            st.pop();
        }
        left[i]++;
        st.push(i);
    }

    while(!st.empty())
        st.pop();


    memset(right, 0, sizeof right);
    for(i = n-1; i >= 0; i--)
    {
        while(!st.empty() && a[st.top()] >= a[i])
        {
            right[i] += right[st.top()];
            st.pop();
        }

        right[i]++;
        st.push(i);
    }

//    cout << "now: \n";
//    for(i = 0; i < n; i++)
//        cout << left[i] << " ";
//    cout << endl;
//    for(i = 0; i < n; i++)
//        cout << right[i] << " ";
//    cout << endl << endl;


    int mx = 0;
    for(i = 0; i < n; i++)
        mx = max(mx, a[i]*(left[i] + right[i] - 1));

    return mx;
}

int main()
{
//    freopen("out.txt", "w", stdout);
    int i, j, t, caseno = 0, mx;
    cin >> t;
    while(t--)
    {
        mx = -1;
        cin >> s[0];
        n = s[0].size();
        for(i = 1; i < n; i++)
            cin >> s[i];
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i == 0 || s[i-1][j] == '0')
                    a[j] = s[i][j] - '0';
                else if(s[i][j] == '0')
                    a[j] = 0;
                else
                    a[j] += s[i][j] - '0';
//                cout << a[j] << " ";
            }
//            cout << endl;
            mx = max(mx, hist());
        }

        cout << mx << endl;
        if(t)
            cout << endl;
    }
}
/*
1

10111000
00010100
00111000
00111010
00111111
01011110
01011110
00011110
*/
