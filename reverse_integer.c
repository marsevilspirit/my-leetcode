int reverse(int x){
    long sum = 0;
    long t;
    while (x != 0) {
        t = x % 10;
        sum = sum * 10 + t;
        x /= 10;
    }
    if(sum < - pow(2,31) || sum > (pow(2,31)-1))    
    {
        return 0;
    }
    else
    return sum;
}
