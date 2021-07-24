#include<bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> ms;

    ms.insert(10);
    ms.insert(10);
    ms.insert(10);
    ms.insert(10);
    ms.insert(15);

    cout << ms.size() << "\n";

    if(ms.find(20) == ms.end())
        cout << "Not found\n";
    else
        cout << "Found\n";

    cout << accumulate(ms.begin(), ms.end(), 0);
}
