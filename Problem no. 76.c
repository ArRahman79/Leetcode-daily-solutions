// 04-02-2024

#define table_size 256
char* minWindow(char* s, char* t) {
    if(s==NULL || t==NULL || strlen(s)==0 || strlen(t)==0)
    {
        return "";
    }

    int dictT[table_size]={0};
    for(int i=0;t[i]!='\0';i++)
    {
        dictT[(int)t[i]]++;
    }

    int req=0;
    for(int i=0;i<table_size;i++)
    {
        if(dictT[i]>0)
            req++;
    }

    int l=0,r=0,formed=0;
    int count[table_size]={0};
    int ans[3]={INT_MAX,0,0};

    while(s[r]!='\0')
    {
        char c=s[r];
        count[(int)c]++;
        if(dictT[(int)c]>0 && count[(int)c] == dictT[(int)c])
        {
            formed++;
        }

        while(l<=r && formed==req)
        {
            c=s[l];
            if(r-l+1<ans[0])
            {
                ans[0]=r-l+1;
                ans[1]=l;
                ans[2]=r;
            }
            count[(int)c]--;
            if(dictT[(int)c]>0 && count[(int)c] < dictT[(int)c])
            {
                formed--;
            }
            l++;
        }
        r++;
    }
    if(ans[0]==INT_MAX)
    {
        return "";
    }

    char *result=(char*)malloc(sizeof(char)*(ans[0]+1));
    if(!result)
    {
        return "";
    }
    strncpy(result,s+ans[1],ans[0]);
    result[ans[0]]='\0';
    return result;
}
