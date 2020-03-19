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

string ans;

void func(char c)
{
    if(c == '+')
        ans += " + ";
    else if(c == '*')
        ans += " * ";
    else if(c == '/')
        ans += " / ";
    else if(c == '-')
        ans += " - ";
    else
        ans += c;
}

int main()
{
    string s;
    cin >> s;
    for_each(s.begin(), s.end(), func);
    cout << ans;
}
