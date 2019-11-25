#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    set<char> st;

    for(auto u : s)
        st.insert(u);

    (st.size()&1) ? cout << "IGNORE HIM!" : cout << "CHAT WITH HER!";
}

