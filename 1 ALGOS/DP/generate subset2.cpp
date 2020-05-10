#include<bits/stdc++.h>
using namespace std;
bool check(int num, int pos)
{
    return num & (1 << pos);
}
int main()
{
    vector <string> v;
    v.push_back("nafis");
    v.push_back("akif");
    v.push_back("johora");
    v.push_back("shahin");
    v.push_back("unicorn");

    int n = v.size();

    for(int x = 0; x < (1 << n); x++)
    {
        printf("%d. ", x+1);
        for(int i = 0; i < n; i++)
        {
            if(check(x, i))
                cout << v[i] << " ";
        }
        printf("\n");
    }
}
