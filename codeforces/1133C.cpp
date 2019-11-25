#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, i, j, m = 1;
    scanf("%d", &n);

    int a[n];

    FORAB(i, 0, n)
        scanf("%d", &a[i]);

    sort(a, a + n);

    vector < int > v;
    v.push_back(a[0]);


    FORAB(i, 1, n)
    {
        while( !v.empty() && a[i] - *(v.begin()) > 5  )
            v.erase(v.begin(), v.begin() + 1);

        v.push_back(a[i]);

        if(m < v.size())
            m = v.size();

        /*FORAB(j, 0, v.size())
            cout << v.at(j) << " ";
        cout << "\n";*/
    }
    printf("%d", m);
}
