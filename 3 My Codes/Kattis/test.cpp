#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, i, j, x = 0, Ans = 0;

    cin >> N;

    int A[N];

    for(i = 0; i < N; ++i)
        cin >> A[i];

    sort(A, A + N);

    for(i = 0; i < N; i++)
    {
        x = 0;

        for(j = i + 1; j < N; ++j)
        {
            if(A[i] == A[j])
            {
                x++;
                cout << x << endl;
            }

            else
            {
                i = j;
                break;
            }

        }

        if((x + 1)  % 2 != 0)
            Ans++;
    }

    cout << Ans << endl;

    return 0;
}
