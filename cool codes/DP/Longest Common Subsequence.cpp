#include<bits/stdc++.h>
using namespace std;

string str1, str2;

int LCS(int len1, int len2)
{
    int i, j;
    //create a matrix of order (len1+1)*(len2+1) to tabulate values

    int arr[len1+1][len2+1];
    //LCS[i][j]=Length of longest common subsequence of str1[0....(i-1)] and str2[0...(j-1)]

    //initializing

    for(i=0;i<=len1;i++)
        arr[i][0]=0;    //empty str2

    for(j=0;j<=len2;j++)
        arr[0][j]=0;   //empty str1

    //now, start filling the matrix row wise
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            //if current character of both strings match
            if(str1[i-1]==str2[j-1])
                arr[i][j]=1+arr[i-1][j-1];

            //mismatch
            else
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);

        }
    }

    for(i = 0; i <= len1; i++)
    {
        for(j = 0; j <= len2; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    //now, return the final value
    return arr[len1][len2];
}

int main()
{
    cout<<"Enter first string   ";
    getline(cin, str1);
    cout<<"Enter second string   ";
    getline(cin, str2);


    int len1=str1.length();  //length of str1
    int len2=str2.length();  //length of str2

    cout<<"Length of longest common subsequence is " << LCS(len1, len2) << endl;

    return 0;
}
