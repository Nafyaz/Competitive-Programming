#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, z = 0, o = 0;
    scanf("%d", &n);
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
        s[i] == '0'? z++ : o++;

    if(z != o)
    {
        cout  << 1 << endl << s;
        return 0;
    }
    cout << 2 << endl << s.substr(0,1) << " " << s.substr(1, s.size() - 1);
}
