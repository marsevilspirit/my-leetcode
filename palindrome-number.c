bool isPalindrome(int x) {
    long num = 0;
    int mun = x;
    while(mun > 0)
    {
       int t = mun % 10;
       mun /= 10;
       num = num * 10 + t;
    }
    if(x == num)
    {
        return true;
    }
    return false;
}
