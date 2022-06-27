//Finds the element that is present for more than N/2 times (if there is any) in O(n) time, O(1) space
ll arr[maxN];

int findMajority()
{
    ll major, cnt = 0, n = arr.size();
        
    for(i = 0; i < n; i++)
    {
        if(cnt == 0)
        {
            major = arr[i];
            cnt = 0;
        }
        
        if(arr[i] == major)
            cnt++;
        else
            cnt--;
    }

    cnt = 0;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == major)
            cnt++;
    }

    if(cnt <= n/2)
        return -1;
    else    
        return major;
}