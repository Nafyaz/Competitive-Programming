#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("out.txt", "w", stdout);

    int n, i, j, a[1009], in_stack[1009], ans;

    while(cin >> n)
    {
        if(!n)
            break;

        while(cin >> a[0])
        {
            if(!a[0])
                break;

            in_stack[a[0]] = 0;
            for(i = 1; i < n; i++)
            {
                cin >> a[i];
                in_stack[a[i]] = 0;
            }

            stack<int> st;
            ans = 1;
            j = 1;

            for(i = 0; i < n && ans; i++)
            {
                if(in_stack[a[i]] && st.top() != a[i])
                    ans = 0;

                while(!in_stack[a[i]] && ans)
                {
                    st.push(j);
                    in_stack[j] = 1;
                    j++;
                }

                if(!st.empty() && ans)
                {
                    in_stack[st.top()] = 0;
                    st.pop();
                }
            }

            cout << (ans? "Yes\n" : "No\n");
        }

        cout << "\n";
    }
}
