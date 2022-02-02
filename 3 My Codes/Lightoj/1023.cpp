#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", t;
    int T, n, k, caseno = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &k);
        t = s.substr(0, n);

        cout << "Case " << ++caseno << ":\n";
        do
        {
            cout << t << "\n";
        }while(next_permutation(t.begin(), t.end()) && --k);
    }
}
