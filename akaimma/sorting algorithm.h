void selection_sort(int *a,int n)
{
    int i,j,min_index,temp;
    for(i=0;i<n;i++)
    {
        min_index=n-1;
        for(j=i;j<n;j++)
        {
            if(a[min_index]>a[j])
                min_index=j;
        }
        if(a[i]>a[min_index])
        {
            temp=a[min_index];
            a[min_index]=a[i];
            a[i]=temp;
        }
    }
}
void bubble_sort(int *a, int n)
{
    int i,j,temp,flag;

    for(i=n-2;i>=0;i--)
    {
        flag=0;
        for(j=0;j<=i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
void insertion_sort(int a[],int n)
{
    int i,j,item;
    for(i=1;i<n;i++)
    {
        item=a[i];
        j=i-1;
        while(j>=0&&a[j]>item)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=item;
    }
}
