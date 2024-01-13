int mySqrt(int x){
    int left,right;
    left=1;right=x/2;
    long long mid;
    if(x==1)
    {
        return 1;
    }
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(mid*mid==x)
        {
            return mid;
        }
        else if(mid*mid<x)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return left-1;
}

