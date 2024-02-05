// 05-02-2024

int firstUniqChar(char* s) {
    int freq[26]={0};
    for(int i=0;i<strlen(s);i++)
    {
        freq[s[i]-'a']++;
    }

    for(int i=0;i<strlen(s);i++)
    {
        if(freq[s[i]-'a']==1)
        {
            return i;
        }
    }
    return -1;
}
