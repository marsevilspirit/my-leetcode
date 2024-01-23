char* reserve(char*s){
    int right=strlen(s)-1,left=0;
    while(left<right){
        char t=s[left];
        s[left]=s[right];
        s[right]=t;
        left++;
        right--;
    }
    return s;
}
char* addBinary(char* a, char* b) {
    reserve(a);
    reserve(b);
    int lena=strlen(a),lenb=strlen(b);
    int len=fmax(lena,lenb),n=0,carry=0;
    char*ret=(char*)malloc(sizeof(char)*(len+2));
    for(int i=0;i<len;i++){
        carry+=i<lena?(a[i]=='1'):0;
        carry+=i<lenb?(b[i]=='1'):0;
    ret[n++]=carry%2+'0';
    carry=carry/2;
    }
    if(carry){ret[n++]='1';}
    ret[n]='\0';
    reserve(ret);
    return ret;
}

