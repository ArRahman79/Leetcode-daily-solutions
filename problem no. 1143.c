//  25-01-2024

int longestCommonSubsequence(char* text1, char* text2) {
    int count[strlen(text1)+1][strlen(text2)+1];
    for(int i=0;i<=strlen(text1);i++)
    {
        for(int j=0;j<=strlen(text2);j++)
        {
            count[i][j]=0;
        }
    }
    for(int i=1;i<=strlen(text1);i++)
    {
        for(int j=1;j<=strlen(text2);j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                count[i][j]=1+count[i-1][j-1];
            }
            else
            {
                count[i][j]=fmax(count[i-1][j],count[i][j-1]);
            }
        }
    }
    return count[strlen(text1)][strlen(text2)];
}
