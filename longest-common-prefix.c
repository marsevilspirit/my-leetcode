char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0)
        return ""; 
    char * predix = strs[0];
    for (int i = 0; i < strsSize; i++) {
        int j = 0;
        while (predix[j] != '\0' && strs[i][j] == predix[j]) {
            j++; 
        }
        predix[j] = '\0';
    }
    return predix;
}
