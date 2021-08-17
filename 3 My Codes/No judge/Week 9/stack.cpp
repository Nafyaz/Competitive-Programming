#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;

    st.push(1);
    st.push(5);
    st.push(7);
    st.push(0);
    st.push(2);

//    for(auto u : st)
//        cout << u << " ";
//    cout << "\n";

//    cout << st.top() << "\n";

    int t = 3;
    while(!st.empty() && t--)
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";

    cout << st.size();
}
