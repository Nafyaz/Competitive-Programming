#include <bits/stdc++.h>

using namespace std;

// Complete the runningTime function below.
int runningTime(vector<int> arr) {
    int i, j, key, cnt = 0;
    for(i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        for(j = i; j > 0 && arr[j-1] > key; j--)
        {
            cnt++;
            arr[j] = arr[j-1];
        }
        arr[j] = key;
    }
    return cnt;
}

int main()
{
    int n, a;
    vector<int> v;
    cin >> n;
    while(n--)
    {
        cin >> a;
        v.push_back(a);
    }
    cout << runningTime(v);
}

