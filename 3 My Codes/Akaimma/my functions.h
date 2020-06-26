int binary_search(int array[],int length,int key)
{
    int low=0,high=length-1,mid;

    while(low<=high)
    {
        mid=low+(high-low)/2;  //mid=(low+high)/2 lekhlam na karon taile data overflow hoite pare
        if(key<array[mid])
            high=mid-1;
        else if(key>array[mid])
            low=mid+1;
        else
            return mid;
    }
    return -1;
}
