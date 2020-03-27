#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define ll long long
vector<string> s;
void permute(string str,int k)
{
    sort(str.begin(), str.end());
    do {
       s.push_back(str);
    } while (next_permutation(str.begin(), str.end()));
    cout << s[k-1] << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        string str;
        str+=string(a-2,'a');
        str+=string(2,'b');
        permute(str,b);
    }
}
