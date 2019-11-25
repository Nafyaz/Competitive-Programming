#include<bits/stdc++.h>
using namespace std;
vector <string> v;
int n, c = 0;
stack <string> x;
void show(stack <string> x)
{
    cout << ++c << ". ";
    while(!x.empty())
    {
        cout << x.top() << " ";
        x.pop();
    }
    cout << endl;
}
void gen(int i)
{
    if(i == n)
    {
        show(x);
        return;
    }
    gen(i+1);
    x.push(v[i]);
    gen(i+1);
    x.pop();
}
int main()
{
    v.push_back("nafis");
    v.push_back("akif");
    v.push_back("johora");
    v.push_back("shahin");
    v.push_back("unicorn");

    n = v.size();

    gen(0);
}
