int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int index=digitsSize-1,pos=1;
    while(index>=0){
        digits[index]+=1;
        if(digits[index]==10){
            digits[index]=0;
            index--;
        }else{
            break;
        }
    }
    if(index==-1){
        int *arr = (int*)malloc(sizeof(int)*(digitsSize+1));
        arr[0]=1;
        for(int i=1;i<=digitsSize;i++){
            arr[i]=digits[i-1];
        }
        *returnSize = digitsSize+1;
        return arr;
    }
    *returnSize = digitsSize;
    return digits;
}

