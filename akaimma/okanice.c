#include <stdio.h>
void makeCombination(int arr1[], int data[], int st, int end,int index, int r);

void CombinationDisplay(int arr1[], int n, int r)
{
    int data[r];
    makeCombination(arr1, data, 0, n-1, 0, r);
}

void makeCombination(int arr1[], int data[], int st, int end,
                     int index, int r)
{

    if (index == r)
    {
        for (int j=0; j<r; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }
    for (int i=st; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr1[i];
        printf("st = %d end = %d index = %d i = %d data = %d \n", st, end, index, i, data[index]);
        makeCombination(arr1, data, i+1, end, index+1, r);
    }
}
int main()
{
    int arr1[105]={0},i,l = 4;
    //while(1)
    {
    //scanf("%d", &l);
    getchar();
    //if(l == 0)
       // break;
    for(i=1; i<=l; i++)
        arr1[i-1]=i;
    CombinationDisplay(arr1, l, 3);
    }
    return 0;
}
